class Solution {
    int solve(int idx, int visit, vector<int>& nums, int k){
        if(idx == nums.size()) return 1;

        bool beautiful = true;
        for(int i = 0; i<idx; ++i){
            if((visit & (1<<i)) && nums[i] + k == nums[idx]){
                beautiful = false; break;
            }
        }
        int ret = 0;
        if(beautiful) ret = solve(idx + 1, visit|(1<<idx), nums, k);
        return ret + solve(idx + 1, visit, nums, k);
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return solve(0,0, nums, k) - 1;
    }
};