class Solution {
    typedef long long ll;
    int dp[1000][1000];
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> cache;

        for(int i = 0; i<n; ++i) cache[nums[i]].push_back(i);

        int ret = 0;
        for(int i = 1; i<n; ++i) for(int j = i + 1; j<n; ++j){
            ll diff = 2LL*nums[i] - nums[j];
            if(diff > INT_MAX || diff < INT_MIN) continue;
            int& temp = dp[i][j];
            if(!cache.count(diff)) continue;
            for(int k : cache[diff]){
                if(k >= i) break;
                temp += dp[k][i] + 1;
            }
            ret += temp;
        }

        return ret;
    }
};