class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;

        vector<int> temp(3);
        for(int i = 0; i<n; i += 3){
            if(nums[i + 2] - nums[i] > k) return vector<vector<int>>();
            for(int j = 0; j<3; ++j) temp[j] = nums[i + j];
            ret.push_back(temp);
        }

        return ret;
    }
};