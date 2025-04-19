class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;

    int dp[1000][1000];
    int solve(int idx, int k, vector<vector<int>>& sum, string& target){
        int n = sum.size(), m = target.size(); // length of string
        if(idx == m) return 1;
        else if(k == n) return 0;
    
        int& ret = dp[idx][k];
        if(ret != -1) return ret;

        ret = solve(idx, k + 1, sum, target);
        int cnt = sum[k][target[idx] - 'a'];
        if(cnt > 0){
            int noSkip = (ll)cnt * solve(idx + 1, k + 1, sum, target) % MOD;
            ret = (ret + noSkip) % MOD;
        }

        return ret;        
    }
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size();
        if(n < m) return 0;
        
        vector<vector<int>> sum(n, vector<int>(26, 0));
        for(string& word : words){
            for(int i = 0; i<n; ++i){
                ++sum[i][word[i] - 'a'];
            }
        }

        memset(dp, -1, sizeof dp);
        return solve(0, 0, sum, target);
    }
};