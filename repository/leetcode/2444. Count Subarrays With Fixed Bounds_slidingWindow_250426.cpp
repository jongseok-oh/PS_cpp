class Solution {
    using ll = long long;
public:
    ll countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int minIdx = -1, maxIdx = -1;
        ll ret = 0;
        
        for(int i = 0, invalidIdx = -1; i<n; ++i){
            if(nums[i] < minK || nums[i] > maxK) invalidIdx = i;
            if(nums[i] == minK) minIdx = i;
            if(nums[i] == maxK) maxIdx = i;

            if(min(minIdx, maxIdx) > invalidIdx){
                ret += min(minIdx, maxIdx) - invalidIdx;
            }
        }

        return ret;
    }
};