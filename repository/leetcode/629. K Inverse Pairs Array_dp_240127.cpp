class Solution {
    const int MOD = 1e9 + 7;
    int dp[1001][1001];
public:
    int kInversePairs(int n, int k) {
        dp[1][0] = 1;

        // 대충 10억 번  연산 하는데 맞음
        // short cut이 잘된 듯 하다 ㅋ
        for(int i = 1; i<n; ++i){
            for(int j = 0; j<=k; ++j){
                if(!dp[i][j]) break;
                for(int kk = 0; kk<=i && kk + j<=k; ++kk){
                    int& ret = dp[i + 1][kk + j];
                    ret = (ret + dp[i][j])%MOD;
                }
            }
        }
        return dp[n][k];
    }
};