class Solution {
    int dp[1002];
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for(int i = 2; i<=n; i++) dp[i] = 1e9;

        for(int i = 0; i<n; ++i){
            dp[i+1] = min(dp[i+1], dp[i] + cost[i]);
            dp[i+2] = min(dp[i+2], dp[i] + cost[i]);
        }

        return dp[n];
    }
};