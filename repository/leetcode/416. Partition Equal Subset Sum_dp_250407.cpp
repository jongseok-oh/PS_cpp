class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum & 1) return false;

        int target = sum/2;
        vector<bool> dp(sum + 1);
        dp[0] = true;
        for(int num : nums){
            for(int j = sum - num; j>=0; --j){
                if(dp[j]) {
                    dp[j + num] = true;
                    if(j + num == target) return true;
                }
            }
        }
        
        return false;
    }
};