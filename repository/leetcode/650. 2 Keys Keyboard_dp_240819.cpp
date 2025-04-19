class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 1e9);
        dp[1] = 0;
        for(int i = 1; i<=n/2; ++i){
            for(int j = 1; j * i + i<=n; ++j){
                int& t = dp[j * i + i];
                if(t > dp[i] + j + 1){
                    t = dp[i] + j + 1;
                }
            }
        }
        return dp[n];
    }
};