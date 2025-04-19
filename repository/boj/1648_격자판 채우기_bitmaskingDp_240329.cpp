#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 9901;
int n, m;
int dp[14 * 14][1 << 15];

int solve(int num, int state) {
    if (num == n * m) return 1;
    int& ret = dp[num][state];
    if (ret != -1) return ret;

    ret = 0;
    if (state & 1) return ret = solve(num + 1, state >> 1);
    if (num / m != n - 1 && !(state & (1 << m))) ret += solve(num + 1, (state | (1 << m)) >> 1);
    if (num % m != m - 1 && !(state & 2)) ret += solve(num + 2, state >> 2);

    return ret %= 9901;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
}