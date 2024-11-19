class Solution {
    using ll = long long;
public:
    ll maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        ll sum = 0;
        for(int i = 0; i<k-1; ++i) {
            ++cnt[nums[i]];
            sum += nums[i];
        }
        
        ll ret = 0;
        for(int i = k -1, n = nums.size(); i<n; ++i){
            sum += nums[i];
            ++cnt[nums[i]];

            if(cnt.size() == k) ret = max(ret, sum);

            sum -= nums[i-(k-1)];
            if(--cnt[nums[i-(k-1)]] == 0){
                cnt.erase(nums[i-(k-1)]);
            }
        }
        
        return ret;
    }
};