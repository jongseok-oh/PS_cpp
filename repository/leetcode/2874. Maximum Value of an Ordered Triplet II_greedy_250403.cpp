class Solution {
    using ll = long long;
public:
    ll maximumTripletValue(vector<int>& nums) {
        ll ret = 0;
        ll _max = max(nums[0], nums[1]), maxDiff = nums[0] - nums[1];
        for(int i = 2, n = nums.size(); i<n; ++i){
            ret = max(ret, maxDiff * nums[i]);
            maxDiff = max(maxDiff, _max - nums[i]);
            _max = max(_max, (ll)nums[i]);
        }

        return ret;
    }
};