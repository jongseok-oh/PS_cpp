class Solution {
    using ll = long long;
    ll solve(int idx, vector<ll>& dp, vector<vector<int>>& questions){
        int n = questions.size();
        if(idx >= n) return 0;
        ll& ret = dp[idx];
        if(ret != -1) return ret;

        ret = 0;

        int point = questions[idx][0], brain = questions[idx][1];
        return ret = max(solve(idx + 1, dp, questions), solve(idx + brain + 1, dp, questions) + point);
    }
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n, -1);
        return solve(0, dp, questions);
    }
};