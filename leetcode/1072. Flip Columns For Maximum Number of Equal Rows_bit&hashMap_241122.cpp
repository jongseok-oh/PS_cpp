class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<bitset<300>, int> bitCnt;
        
        int ret =0;
        for(auto& row : matrix){
            bitset<300> bits;
            for(int i = 0; i<m; ++i) {
                bits[i] = row[i] == row[0];
            }
            ++bitCnt[bits];
            ret = max(ret, bitCnt[bits]);
        }

        return ret;
    }
};