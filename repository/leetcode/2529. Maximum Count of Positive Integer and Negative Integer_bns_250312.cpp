class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int negCnt = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        int posCnt = n - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());
        return max(negCnt, posCnt);
    }
};