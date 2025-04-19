#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int p, q;
int release[102];
int dp[101][102];

int solve(int s, int e) {
	if (s + 1 == e) return 0;
	int& ret = dp[s][e];
	if (ret != -1) return ret;

	ret = 1e9;
	int gold = release[e] - release[s]- 2;
	for (int i = s + 1; i < e; ++i) {
		ret = min(gold + solve(s, i) + solve(i, e), ret);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> p>>q;
		release[0] = 0;
		release[q + 1] = p+1;
		for (int i = 1; i <= q; ++i) cin >> release[i];
		
		memset(dp, -1, sizeof dp);
		cout << "Case #" << t << ": " << solve(0, q + 1) << "\n";
	}
}