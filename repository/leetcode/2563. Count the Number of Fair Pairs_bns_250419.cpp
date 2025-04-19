class Solution {
    using ll = long long;
public:
    ll countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll ret = 0;
        for(int i = 0, n = nums.size(); i<n-1; ++i){
            auto lowIt = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto upperIt = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            ret += upperIt - lowIt;
        }
        return ret;
    }
};