class Solution {
    int dp[16][1<<17];
    int solve(int idx, int temp, int tot, vector<int>& nums){
        if(idx == nums.size()) return temp == tot;
        int&ret = dp[idx][temp];
        if(ret != -1) return ret;
        ret = 0;
        ret += solve(idx + 1, temp | nums[idx], tot, nums);
        ret += solve(idx + 1, temp, tot, nums);
        return ret;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int tot = 0;
        for(int num : nums) tot |= num;
        memset(dp, -1, sizeof dp);
        return solve(0, 0, tot, nums);
    }
};