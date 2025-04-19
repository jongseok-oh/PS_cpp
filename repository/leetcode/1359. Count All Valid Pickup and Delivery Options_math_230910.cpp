class Solution {
    const int MOD = 1e9 + 7;
public:
    int countOrders(int n) {
        int ret = 1;

        for(int i = 2; i<=n; ++i)
            ret = 1LL * ret * (2*i - 1) * i % MOD;
        
        return ret;
    }
};