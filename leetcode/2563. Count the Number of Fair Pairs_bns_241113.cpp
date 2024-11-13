class Solution {
    using ll = long long;
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        ll ret = 0;
        for(int i = 0, n = nums.size(); i<n; ++i)
        {
            int lIdx = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int uIdx = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            if(lIdx < uIdx) ret += uIdx - lIdx;
        }

        return ret;
    }
};