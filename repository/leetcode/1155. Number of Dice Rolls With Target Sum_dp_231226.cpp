class Solution {
    const int MOD = 1e9 + 7;
    int dp[1001][31];
public:
    int numRollsToTarget(int n, int k, int target) {
        for(int i = 1; i<=k; ++i) dp[i][1] = 1;

        for(int i = 2; i<=n; ++i) for(int j = target; j>0; --j){
            for(int kk = 1; kk <= k && j - kk > 0; ++kk){
                if(!dp[j - kk][i-1]) continue;
                dp[j][i] += dp[j - kk][i-1];
                dp[j][i] %= MOD;
            }
        }

        return dp[target][n];
    }
};