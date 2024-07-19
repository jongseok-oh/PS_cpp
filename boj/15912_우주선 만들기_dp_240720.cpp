#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;

int n;
ll w[1000], e[1000], dp[1000];

ll solve(int idx) {
    if (idx == n) return 0;
    ll& ret = dp[idx];
    if (ret != -1) return ret;

    ret = 1e15;
    ll maxW = -1, maxE = -1;
    for (int i = idx; i < n; ++i) {
        maxW = max(maxW, w[i]);
        maxE = max(maxE, e[i]);
        ret = min(ret, maxW * maxE + solve(i + 1));
    }

    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < n; ++i) cin >> e[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0);
}