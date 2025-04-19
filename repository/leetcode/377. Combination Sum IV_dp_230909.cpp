class Solution {
    int dp[1001];

    int solve(int tTarget, vector<int>& nums){
        if(!tTarget) return 1;

        int& ret = dp[tTarget];

        if(ret != -1) return ret;

        ret = 0;

        for(int& num: nums){
            if(num <= tTarget)
                ret += solve(tTarget - num, nums);
        }

        return ret;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof dp);
        return solve(target, nums);
    }
};