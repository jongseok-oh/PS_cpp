class Solution {
    vector<int> plus(vector<int>& code, int k){
        int sum = 0, n = code.size();
        for(int i = 1; i<k; ++i){
            sum += code[i];
        }
        vector<int> ret(n);
        for(int i = 0; i<n; ++i){
            sum += code[(i + k)%n];
            ret[i] = sum;
            sum -= code[(i+1)%n];
        }
        return ret;
    }
    vector<int> minus(vector<int>& code, int k){
        int sum = 0, n = code.size();
        for(int i = abs(k); i>1; --i){
            sum += code[-i + n];
        }
        vector<int> ret(n);
        for(int i = 0; i<n; ++i){
            sum += code[(i-1 + n)%n];
            ret[i] = sum;
            sum -= code[(i + k + n)%n];
        }
        return ret;
    }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0) return vector<int>(n);
        return k>0?plus(code, k):minus(code, k);
    }
};