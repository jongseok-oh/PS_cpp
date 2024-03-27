class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int mult = 1, n = nums.size(), ret = 0;
        for(int j = 0, i =0; j<n; ++j){
            mult *= nums[j];
            while(i<n && mult >= k) mult /= nums[i++];
            ret += j - i + 1;
        }
        return ret;
    }
};