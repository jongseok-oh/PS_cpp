class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        for(auto& q : queries){
            int l = q[0], r= q[1];
            --prefixSum[l];
            ++prefixSum[r + 1];
        }
        for(int i = 0; i<n; ++i){
            if(prefixSum[i] + nums[i] > 0) return false;
            prefixSum[i+1] += prefixSum[i];
        }

        return true;
    }
};