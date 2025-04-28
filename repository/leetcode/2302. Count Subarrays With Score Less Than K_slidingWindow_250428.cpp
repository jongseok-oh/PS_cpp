class Solution {
    using ll = long long;
public:
    ll countSubarrays(vector<int>& nums, ll k) {
        ll sum = 0, ret = 0;
        for(int i = 0, j = 0, n = nums.size(); i<n; ++i){
            if(j < i) j = i;
            while(j < n && (sum + nums[j]) * (j - i + 1) < k){
                sum += nums[j++];
            }
            if(j > i) {
                ret += j - i;
                sum -= nums[i];
            }
        }
        return ret;
    }
};