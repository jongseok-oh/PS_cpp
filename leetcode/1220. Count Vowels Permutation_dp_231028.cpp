class Solution {
    const int MOD = 1e9 + 7;
    int dp[20000][5];
    // a e i o u
public:
    int countVowelPermutation(int n) {

        vector<vector<int>> need = {{1,2,4}, {0,2}, {1,3}, {2}, {2,3}};

        for(int i = 0; i<5; i++)
            dp[0][i] = 1;
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<5; ++j){
                for(int& idx : need[j]){
                    dp[i][j] += dp[i - 1][idx];
                    dp[i][j] %= MOD;
                }
            }
        }

        int ret = 0;
        for(int j = 0; j<5; ++j){
            ret += dp[n-1][j];
            ret %= MOD;
        }

        return ret;
    }
};