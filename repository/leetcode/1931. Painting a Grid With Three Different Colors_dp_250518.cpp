class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;

    int pow(int m){
        int ret = 1, a = 3;
        while(m){
            if(m&1) ret *= a;
            a *= a;
            m >>= 1; 
        }
        return ret;
    }

    bool isValid(int mask, int m){
        int prev = -1, diffCnt = 0;
        for(int i = 0; i<m; ++i){
            if(mask % 3 != prev){
                ++diffCnt;
            }
            prev = mask % 3;
            mask /= 3;
        }
        return diffCnt == m;
    }

    bool isValid(int mask1, int mask2, int m){
        if(!isValid(mask1, m) || !isValid(mask2, m)) return false;

        for(int i = 0; i<m; ++i){
            if(mask1 % 3 == mask2 % 3) return false;
            mask1 /= 3; mask2 /= 3;
        }
        
        return true;
    }
public:
    int colorTheGrid(int m, int n) {
        int totalMask = pow(m);
        vector<vector<ll>> dp(n, vector<ll>(totalMask));

        for(int i = 0; i<totalMask; ++i){
            if(isValid(i, m)) dp[0][i] = 1;
        }

        for(int i = 1; i<n; ++i){
            for(int j = 0; j<totalMask; ++j){
                ll& tDp = dp[i][j];
                for(int k = 0; k<totalMask; ++k){
                    if(isValid(j, k, m)){
                        tDp = (tDp + dp[i-1][k]) % MOD;
                    }
                }
            }
        }

        int ret = 0;
        for(int i = 0; i<totalMask; ++i){
            ret = (ret + dp[n-1][i])%MOD;
        }

        return ret;
    }
};