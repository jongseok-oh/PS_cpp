class Solution {
    int dp[300][11];
    int sufix[300];
    int solve(int idx, int d, vector<int>& jd){
        if(d == 1) return sufix[idx];
        int& ret = dp[idx][d];
        if(ret != -1) return ret;

        ret = 1e9;
        int _max = -1, n = jd.size();

        for(int i = idx; i<n-1; ++i){
            _max =max(_max, jd[i]);
            ret = min(ret, _max + solve(i + 1, d-1, jd));
        }

        return ret;
    }
public:
    int minDifficulty(vector<int>& jd, int d) {
        if(jd.size() < d) return -1;
        memset(dp, -1, sizeof dp);

        int n = jd.size();
        sufix[n-1] = jd[n-1];
        for(int i = n-2; i>=0; --i) sufix[i] = max(sufix[i+1], jd[i]);

        return solve(0, d, jd);
    }
};