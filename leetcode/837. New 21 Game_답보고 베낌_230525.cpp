class Solution {

double dp[10001];

public:
    double new21Game(int n, int k, int maxPts) {
        if(!k || n >= k + maxPts) return 1.0;

        dp[0] = 1;

        double tsum = 1, ret = 0;
        for(int i = 1; i<=n; i++){
            dp[i] = tsum/maxPts;

            if(i < k) tsum += dp[i];
            else ret += dp[i];

            if(i >= maxPts) tsum -= dp[i - maxPts];
        }
        return ret;
    }
};