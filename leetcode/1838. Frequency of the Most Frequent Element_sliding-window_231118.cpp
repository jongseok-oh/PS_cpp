class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ret = 1, n = nums.size();

        for(int i = 0, j = 1; i<n; ++i){
            while(j<n && k >= 1LL*(nums[j] - nums[j-1]) * (j - i)){
                k -= (nums[j] - nums[j-1]) * (j - i);
                ++j;
            }
            ret = max(ret, j - i);
            if(j == n) break;

            k += nums[j-1]-nums[i];
        }

        return ret;
    }
};