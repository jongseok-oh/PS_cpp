class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ret(n, vector<int>(m));

        for(int i = 0, j = 0; i<n&& j<m; i += (rowSum[i] ==0), j += (colSum[j] == 0)){
            int t = min(rowSum[i], colSum[j]);
            ret[i][j] = t;
            rowSum[i] -= t;
            colSum[j] -= t;
        }

        return ret;
    }
};