class Solution {
    #define ll long long
    const int MOD = 1e9 + 7;

    ll dp[101][101];

    ll solve(int n, int goal, int k){
        if(!n && ! goal) return 1;
        if(!n || !goal) return 0;

        ll& ret = dp[n][goal];

        if(ret != -1) return ret;

        return ret = (solve(n -1, goal -1, k) * n + solve(n, goal -1, k) * max(n-k, 0)) % MOD;
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof dp);
        return solve(n, goal, k);
    }
};