class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
public:
    int countGoodNumbers(ll n) {
        ll ret = n&1?5:1;
        n >>= 1;
        
        ll _pow = 20;
        for(int i = 1; n && i<64; ++i, n>>=1){
            if(n&1){
                ret = (ret * _pow) % MOD;
            }
            _pow = _pow * _pow % MOD;
        }
        return ret;
    }
};