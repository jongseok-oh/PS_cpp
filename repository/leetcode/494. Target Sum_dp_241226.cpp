class Solution {
    const int _max = 40001;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(_max);
        dp[_max/2] = 1;
        for(int num : nums){
            vector<int> temp(_max);
            for(int j = 0; j<_max; ++j){
                if(dp[j] == 0) continue;
                temp[j - num] += dp[j];
                temp[j + num] += dp[j];
            }
            dp = temp;
        }
        return dp[target + _max/2];
    }
};