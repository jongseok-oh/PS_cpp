class Solution {
    int solve(int idx, vector<int>& dp, vector<vector<int>>& canDiv){
        int& ret = dp[idx];
        if(ret != -1) return ret;

        ret = 1;
        for(int mother : canDiv[idx]){
            ret = max(ret, 1 + solve(mother, dp, canDiv));
        }

        return ret;
    }
    void remake(int idx, vector<int>& ret, vector<int>& nums,
    vector<int>& dp, vector<vector<int>>& canDiv){
        ret.push_back(nums[idx]);
        for(int next : canDiv[idx]){
            if(dp[idx] - 1 == dp[next]){
                remake(next, ret, nums, dp, canDiv);
                break;
            }
        }
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> canDiv(n);
        for(int i = n-2; i>=0; --i){
            for(int j = i + 1; j<n; ++j){
                if(nums[j] % nums[i] == 0){
                    canDiv[i].push_back(j);
                }
            }
        }

        vector<int> dp(n, -1);
        int maxLenStart = -1;
        for(int i = 0; i<n; ++i){
            solve(i, dp, canDiv);
            if(maxLenStart == -1 || dp[maxLenStart] < dp[i]){
                maxLenStart = i;
            }
        }

        vector<int> ret;
        remake(maxLenStart, ret, nums, dp, canDiv);
        return ret;
    }
};