class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ret = 0;
        for(int i = 0, n = nums.size(); i<n-2; ++i){
            if((nums[i] + nums[i + 2])*2 == nums[i+1]){
                ++ret;
            }
        }
        
        return ret;
    }
};