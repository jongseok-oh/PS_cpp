#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m;

int len = 0;
pii items[1500];

int dp[1500][10001];

int solve(int idx, int w) {
	if (w < 0) return -1e9;
	if (idx == len) return 0;
	int& ret = dp[idx][w];
	if (ret != -1) return ret;
	ret = 0;
	return ret = max(
		solve(idx + 1, w),
		solve(idx + 1, w - items[idx].first) + items[idx].second
	);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	int v, c, k;
	for (int i = 0; i < n; i++) {
		cin >> v >> c >> k;

		for (int i = k; i > 0; i >>= 1) {
			int num = i - (i >> 1);
			items[len++] = { v * num, c * num };
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0,m);
}