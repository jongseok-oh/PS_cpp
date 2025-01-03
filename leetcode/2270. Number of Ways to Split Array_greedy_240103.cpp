class Solution {
    using ll = long long;
public:
    int waysToSplitArray(vector<int>& nums) {
        ll right = 0;
        for(int num : nums) right += num;

        int n = nums.size();
        ll left = 0, ret = 0;
        for(int i = 0; i<n-1; ++i){
            int num = nums[i];
            left += num;
            right -= num;
            if(left >= right) ++ret;
        }

        return ret;
    }
};