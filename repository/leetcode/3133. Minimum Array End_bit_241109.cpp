class Solution {
    using ll = long long;
public:
    ll minEnd(int n, int x) {
        ll result = x; --n;

        for (ll mask = 1; n > 0; mask <<= 1) {
            if (!(mask & x)) {
                result |= (n & 1) * mask;
                n >>= 1;
            }
        }

        return result;
    }
};