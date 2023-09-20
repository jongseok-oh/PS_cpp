class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(int num: nums) total += num;

        int tar = total - x;

        if(tar < 0) return -1;

        int sum = 0, ret = 1e9;
        for(int left = 0, right = 0; left <= right; ++left){
            while(right < n && sum < tar)
                sum += nums[right++];
            
            if(sum == tar)
                ret = min(ret, n - (right - left));
            
            sum -= nums[left];
        }

        return ret==1e9?-1:ret;
    }
};