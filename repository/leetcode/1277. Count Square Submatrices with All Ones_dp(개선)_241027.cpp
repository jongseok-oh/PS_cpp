class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m+1));
        int ret = 0;
        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j){
            if(matrix[i][j] == 1){
                ret += dp[i+1][j+1] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i][j]});
            }
        }

        return ret;
    }
};