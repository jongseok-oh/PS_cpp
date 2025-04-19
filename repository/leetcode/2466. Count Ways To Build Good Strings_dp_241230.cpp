class Solution {
    const int MOD = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;

        for(int i = 0, n = high - min(zero, one); i<=n; ++i){
            if(dp[i] == 0) continue;
            if(i + zero <= high) dp[i+zero] = (dp[i+zero] + dp[i]) % MOD;
            if(i + one <= high) dp[i + one] = (dp[i + one] + dp[i]) % MOD;
        }

        int ret = 0;
        for(int i = low; i<=high; ++i){
            ret = (ret + dp[i]) % MOD;
        }

        return ret;
    }
};