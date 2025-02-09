class Solution {
    using ll = long long;
public:
    ll countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        
        for(int i = 0; i<n; ++i){
            ++cnt[nums[i] - i];
        }

        ll ret = (ll)n * (n-1)/2;
        for(auto& [k, v] : cnt){
            ret -= (ll)v * (v - 1)/2;
        }

        return ret;
    }
};