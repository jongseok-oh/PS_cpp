class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ret = 0, n = nums.size();
        for(int i = 0; i<n-2; ++i){
            if(nums[i] == 0){
                ++ret;
                for(int j = 0; j<3; ++j){
                    nums[i+j] ^= 1;
                }
            }
        }
        return (nums[n-2] == 1 && nums[n-1] == 1) ? ret:-1;
    }
};