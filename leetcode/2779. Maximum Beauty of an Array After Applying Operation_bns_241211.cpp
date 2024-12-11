class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = nums.front() + k, high = nums.back() - k;
        if(low >= high) return nums.size();

        int ret = 1;
        for(int x = low; x<=high; ++x){
            int start = lower_bound(nums.begin(), nums.end(), x - k) - nums.begin();
            int end = lower_bound(nums.begin(), nums.end(), x + k + 1)- nums.begin() - 1;
            ret = max(ret , end - start + 1);
        }

        return ret;
    }
};