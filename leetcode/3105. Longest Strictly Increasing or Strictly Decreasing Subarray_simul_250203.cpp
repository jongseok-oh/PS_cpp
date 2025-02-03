class Solution {
    int increase(vector<int>& nums){
        int len = 1, ret = 1;
        for(int i = 1, n = nums.size(); i<n; ++i){
            if(nums[i-1] < nums[i]) ++len;
            else len = 1;
            ret = max(ret, len);
        }
        return ret;
    }
    int decrease(vector<int>& nums){
        int len = 1, ret = 1;
        for(int i = 1, n = nums.size(); i<n; ++i){
            if(nums[i-1] > nums[i]) ++len;
            else len = 1;
            ret = max(ret, len);
        }
        return ret;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(increase(nums), decrease(nums));
    }
};