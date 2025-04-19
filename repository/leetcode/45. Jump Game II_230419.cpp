class Solution {
public:
    int dp[10000];
    int jump(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i<n; i++) dp[i] = 1e9;

        for(int i = 0; i<n; i++){
            for(int j = 1, jump = nums[i]; i + j <n && j<=jump; j++){
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }
        return dp[n-1];
    }
};