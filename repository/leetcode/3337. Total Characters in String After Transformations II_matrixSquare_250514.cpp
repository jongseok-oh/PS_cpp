class Solution {
    const static int MOD = 1e9 + 7;
    using ll = long long;
    class Matrix{
        int _size;
        vector<vector<int>> _mat;
    public:
        Matrix(int size){
            _size = size;
            _mat = vector<vector<int>>(size, vector<int>(size));
        }
        int* operator[](int i) {return _mat[i].data();}
        const int* operator[](int i) const {return _mat[i].data();}

        Matrix operator*(const Matrix& r) const{
            Matrix ret = Matrix(_size);
            for(int i = 0; i<_size; ++i){
                for(int j = 0; j<_size; ++j){
                    for(int k = 0; k<_size; ++k){
                        ret[i][j] = ((ll)_mat[i][k] * r[k][j] + ret[i][j]) % MOD;
                    }
                }
            }
            
            return ret;
        }
    };
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix mat = Matrix(26);
        for(int i = 0; i<26; ++i){
            for(int j = 0; j<nums[i]; ++j){
                mat[i][(i + j + 1)%26] = 1;
            }
        }

        Matrix temp(26);
        for(int i = 0; i<26; ++i) temp[i][i] = 1;
        while(t){
            if(t & 1) temp = temp * mat;
            mat = mat * mat;
            t >>= 1;
        }

        vector<int> cnt(26), ans(26);
        for(char c : s) ++cnt[c - 'a'];
        
        for(int i = 0; i<26; ++i){
            for(int j = 0; j<26; ++j){
                ans[j] = ((ll)cnt[i] * temp[i][j] + ans[j]) % MOD;
            }
        }

        int ret = 0;
        for(int a : ans){
            ret = (ret + a) % MOD;
        }

        return ret;
    }
};