class Solution {
    int dfs(vector<int>& nums, int index, int currentXor) {
        if (index == nums.size()) return currentXor;
        int include = dfs(nums, index + 1, currentXor ^ nums[index]);
        int exclude = dfs(nums, index + 1, currentXor);
        return include + exclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};