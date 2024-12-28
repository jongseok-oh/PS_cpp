class Solution {
    int _k, _n;
    vector<int> prefixSum;
    int getSum(int from, int to){
        if(from == 0) return prefixSum[to];
        return prefixSum[to] - prefixSum[from-1];
    }
    int solve(int idx, int order, vector<vector<int>>& dp, vector<vector<bool>>& skip){
        if(
            idx > _n - (3 - order) * _k
            || order == 3
        ) return 0;
        int& ret = dp[idx][order];
        if(ret != -1) return ret;
        ret = solve(idx + _k, order + 1, dp, skip) + getSum(idx, idx + _k - 1);
        int _skip = solve(idx + 1, order, dp, skip);

        if(_skip > ret){
            ret = _skip;
            skip[idx][order] = true;
        }

        return ret;
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        prefixSum.resize(n);
        prefixSum[0] = nums[0];
        for(int i = 1; i<n; ++i){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        _k = k; _n = n;
        vector<vector<int>> dp(n, vector<int>(3, -1));
        vector<vector<bool>> skip(n, vector<bool>(3));
        int _max = solve(0, 0, dp, skip);

        int sum = _max, idx = 0;
        vector<int> ret;
        for(int order = 0; order<3; ++order){
            for(int i = idx; i<n; ++i){
                if(dp[i][order] == sum && !skip[i][order]){
                    ret.push_back(i);
                    idx = i + k;
                    sum -= getSum(i, i + k - 1);
                    break;
                }
            }
        }

        return ret;
    }
};