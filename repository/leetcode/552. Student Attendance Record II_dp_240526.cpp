class Solution {
    const int mod = 1e9 + 7;
    int dp[100001][3][2]; // idx, L, A
public:
    int checkRecord(int n) {
        dp[0][0][0] = 1;

        for(int i = 1; i<=n; ++i){
            // P
            for(int j = 0; j<3; ++j) for(int k = 0; k<2; ++k){
                dp[i][0][k] = (dp[i][0][k] + dp[i-1][j][k])%mod;
            }
            // A
            for(int j = 0; j<3; ++j) {
                dp[i][0][1] = (dp[i][0][1] + dp[i-1][j][0])%mod;
            }
            // L
            for(int j = 0; j<2; ++j) for(int k = 0; k<2; ++k){
                dp[i][j+1][k] = (dp[i][j+1][k] + dp[i-1][j][k])%mod;
            }
        }

        int ret = 0;
        for(int i = 0; i<3; ++i) for(int j = 0; j<2; ++j)
            ret = (ret + dp[n][i][j])%mod;

        return ret;
    }
};