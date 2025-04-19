class Solution {
    int dp[2000];
    int cnt[2000];
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int maxLen = 1;
        for(int i = 0; i<n; i++){
            if(!dp[i]) dp[i] = 1, cnt[i] = 1;
            for(int j = i + 1; j<n; j++){
                if(nums[i] < nums[j]){
                    if(dp[i] + 1 > dp[j]){
                        dp[j] = dp[i] + 1;
                        cnt[j] = cnt[i];
                        maxLen = max(dp[j], maxLen);
                    }else if(dp[i] + 1 == dp[j]) cnt[j] += cnt[i];
                }
            }
        }

        int ret = 0;

        for(int i = 0; i<n; i++)
            if(dp[i] == maxLen) ret += cnt[i];
        
        return ret;
    }
};