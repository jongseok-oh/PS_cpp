class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int _size = original.size();
        if(_size != m * n) return {};

        vector<vector<int>> ret(m, vector<int> (n));
        for(int i = 0; i<_size; ++i){
            ret[i/n][i%n] = original[i];
        }

        return ret;
    }
};