class Solution {
    const int MOD = 1e9 + 7;
    const vector<vector<int>> from = {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
    int _copy[10];
    int dp[10] = {1,1,1,1,1,1,1,1,1,1};
public:
    int knightDialer(int n) {
        while(--n){
            for(int i = 0; i<10; i++) _copy[i] = dp[i];
            memset(dp, 0, sizeof dp);

            for(int i = 0; i<10; i++){
                for(const int& f: from[i]){
                    dp[i] += _copy[f];
                    dp[i] %= MOD;
                }
            }
        }

        int ret = 0;
        for(int i = 0; i<10; ++i) ret += dp[i], ret %=MOD;

        return ret;
    }
};