class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        int n = nums.size(), incCnt = 1;
        for(int i = 1; i<k-1; ++i){
            if(nums[i - 1] + 1 == nums[i]) ++incCnt;
            else incCnt = 1;
        }

        vector<int> ret(n - k + 1);
        for(int i = k -1; i<n; ++i){
            if(nums[i - 1] + 1 == nums[i]) ++incCnt;
            else incCnt = 1;

            ret[i - (k-1)] = incCnt>=k?nums[i]:-1;
        }
        
        return ret;
    }
};