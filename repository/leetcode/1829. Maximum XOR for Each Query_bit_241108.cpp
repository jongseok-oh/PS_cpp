class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ret(n);
        int tot = 0, mask = (1<<maximumBit) - 1;
        for(int i = 0; i<n; ++i){
            tot ^= nums[i];
            ret[n-i-1] = tot & mask ^ mask;
        }

        return ret;
    }
};