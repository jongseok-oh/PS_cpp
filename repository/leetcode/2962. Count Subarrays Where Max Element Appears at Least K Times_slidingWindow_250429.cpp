class Solution {
    using ll = long long;
public:
    ll countSubarrays(vector<int>& nums, int k) {
        int _max = *max_element(nums.begin(), nums.end());

        ll ret = 0;
        for(int i = 0, j = 0, cnt = 0, n = nums.size(); i<n; ++i){
            while(j < n && cnt < k){
                if(nums[j++] == _max) ++cnt;
            }
            if(cnt == k) ret += n - j + 1;
            if(nums[i] == _max) --cnt;
        }

        return ret;
    }
};