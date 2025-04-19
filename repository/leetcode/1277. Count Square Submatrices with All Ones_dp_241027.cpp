class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ret = 0;
        vector<vector<bool>> dp(n, vector<bool>(m));

        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j){
            ret += dp[i][j] = (matrix[i][j] == 1);
        }

        for(int len = 2, maxLen = min(n, m); len<=maxLen; ++len){
            int plus = len -1;
            for(int i = 0; i<n-plus; ++i) for(int j = 0; j<m-plus; ++j){
                ret += dp[i][j] = (dp[i][j] && dp[i][j+1] && dp[i+1][j] && matrix[i+plus][j+plus]);
            }
        }
        return ret;
    }
};