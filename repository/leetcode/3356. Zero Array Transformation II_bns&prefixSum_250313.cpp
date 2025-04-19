class Solution {
    bool check(int k, vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<int> prefixSum(n);
        for(int i = 0; i<k; ++i){
            auto& q = queries[i];
            int l = q[0], r = q[1], val = q[2];
            prefixSum[l] -= val;
            if(r+1 < n) prefixSum[r + 1] += val;
        }
        if(nums[0] + prefixSum[0] > 0) return false;
        for(int i = 1; i<n; ++i){
            prefixSum[i] += prefixSum[i-1];
            if(nums[i] + prefixSum[i]> 0) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int low = -1, high = n + 1;
        while(low + 1 < high){
            int k = (low + high)>>1;
            if(check(k, nums, queries)){
                high = k;
            }else low = k;
        }
        return high == n + 1? -1 : high;
    }
};