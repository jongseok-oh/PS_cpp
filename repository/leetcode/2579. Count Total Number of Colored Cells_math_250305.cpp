class Solution {
    using ll = long long;
public:
    ll coloredCells(int n) {
        return 1 + (ll)4 * n * (n-1) / 2;
    }
};