class Solution {
    int dp[10001];
public:
    int numSquares(int n) {
        memset(dp, 0x7f, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 1; j<=100; ++j){
                if(i + j * j > n) break;
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};