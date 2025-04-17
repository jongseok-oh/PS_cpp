class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ret = 0;
        for(int i = 0, n = nums.size(); i<n; ++i){
            for(int j = i + 1; j<n; ++j){
                if(nums[i] == nums[j] && i*j%k == 0) ++ret;
            }
        }

        return ret;
    }
};