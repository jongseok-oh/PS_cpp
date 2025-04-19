class Solution {
    const int MOD = 1e9 + 7;
    
    int dp[501][251];
public:
    int numWays(int steps, int arrLen) {
        int n = steps, m = min(n/2 + 1, arrLen);

        dp[0][0] = 1;
        for(int i = 1; i<=steps; ++i){
            for(int j = 0; j<m; j++){
                dp[i][j] = dp[i-1][j];
                if(j != 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if(j != m-1) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }

        return dp[n][0];
    }
};