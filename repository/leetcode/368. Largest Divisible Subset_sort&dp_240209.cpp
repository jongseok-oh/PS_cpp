class Solution {
    int dp[1000];
    int n;

    int solve(int idx, vector<int>& nums){
        if(idx == n) return 0;
        int& ret = dp[idx];
        if(ret != -1) return ret;

        ret = 1;

        for(int i = idx + 1; i<n; ++i){
            if(nums[i] % nums[idx] == 0){
                ret = max(ret , 1 + solve(i, nums));
            }
        }
        return ret;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memset(dp, -1, nums.size()*4);

        n = nums.size();
        int idx = -1, maxLen = -1;

        for(int i = 0;i<n; ++i){
            int len = solve(i, nums);
            if(len > maxLen){
                idx = i; maxLen = len;
            }
        }
        vector<int> ret(1, nums[idx]);

        for(int i = idx + 1; i<n; ++i){
            if(nums[i] % nums[idx] == 0 && dp[idx] == dp[i] + 1){
                ret.push_back(nums[i]);
                idx = i;
            }
        }
        return ret;
    }
};