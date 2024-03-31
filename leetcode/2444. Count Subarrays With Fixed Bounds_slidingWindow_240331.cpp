class Solution {
    typedef long long ll;
public:
    ll countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ret = 0;
        int minIdx = -1, maxIdx = -1, pibot = -1, n = nums.size();

        for(int i = 0; i<n; ++i){
            int num = nums[i];
            if(num < minK || num > maxK) pibot = i;
            
            if(num == minK) minIdx = i;
            if(num == maxK) maxIdx = i;

            if(minIdx > pibot && maxIdx > pibot)
                ret += min(minIdx, maxIdx) - pibot;
        }

        return ret;
    }
};