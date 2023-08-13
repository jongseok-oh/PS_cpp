class Solution {
    int dp[100000];

    int solve(int idx, int n, vector<int>& nums){
        if(idx == n) return 2;
        
        int& ret = dp[idx];

        if(ret) return ret;

        if(idx + 2 <= n && nums[idx] == nums[idx + 1]){
            if(solve(idx + 2, n, nums) == 2) return ret = 2;

            if(idx + 3 <= n && nums[idx] == nums[idx + 2]
            && solve(idx + 3, n, nums) == 2) return ret = 2;
        }

        if(idx + 3 <= n && nums[idx] == nums[idx + 1] -1
        && nums[idx] == nums[idx + 2] - 2 && solve(idx + 3, n, nums) == 2)
            return ret = 2;
        
        return ret = 1;
    }

public:
    bool validPartition(vector<int>& nums) {
        return solve(0, nums.size(), nums) == 2;
    }
};