class Solution {
    vector<int> sum = vector<int>(1001);
    int _max = -1;
    void merge(vector<vector<int>>& nums){
        for(auto& num : nums){
            int id = num[0], value = num[1];
            sum[id] += value;
            _max = max(_max, id);
        }
    }
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        merge(nums1); merge(nums2);
        vector<vector<int>> ret;
        for(int i = 1; i<=_max; ++i){
            if(sum[i]) ret.push_back({i, sum[i]});
        }
        return ret;
    }
};