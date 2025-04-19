class Solution {
    void makeSubsets(int idx, vector<int>& nums, vector<int> temp, vector<vector<int>>& ret){
        ret.push_back(temp);
        for(int i = idx, n = nums.size(); i<n; ++i){
            vector<int> tt = temp;
            tt.push_back(nums[i]);
            makeSubsets(i + 1, nums, tt , ret);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        makeSubsets(0, nums, {}, ret);
        return ret;
    }
};