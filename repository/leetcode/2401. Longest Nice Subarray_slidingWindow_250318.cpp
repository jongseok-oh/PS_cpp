class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int prevBit = 0, ret = 0;
        for(int i = 0, j = 1, n = nums.size(); i<n; ++i, j = max(j, i + 1)){
            prevBit |= nums[i];
            while(j<n && (prevBit & nums[j]) == 0) {
                prevBit |= nums[j++];
            }
            ret = max(ret, j - i);
            prevBit ^= nums[i];
        }
        return ret;
    }
};
