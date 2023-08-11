class Solution {
    int dp[5001];
public:
    int change(int amount, vector<int>& coins) {
        dp[0] = 1;

        for(int c: coins) for(int i = 0; i<= amount - c; i++)
            if(dp[i]) dp[i + c] += dp[i];
        
        return dp[amount];
    }
};