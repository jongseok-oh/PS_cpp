class Solution {
    const int MOD = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for(int i = 0; i<n; ++i){
            int tsum = 0;
            for(int j = i; j<n; ++j){
                tsum += nums[j];
                sums.push_back(tsum);
            }
        }
        sort(sums.begin(), sums.end());
        int ret = 0;
        for(int i = left -1; i<right; ++i){
            ret = (ret + sums[i]) % MOD;
        }
        return ret;
    }
};