#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[101][1001];

struct bag
{
	int v, c;
}bags[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n, k; cin >> n >> k;

		for (int i = 1; i <= n; i++) cin >> bags[i].v >> bags[i].c;

		for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - bags[i].v >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - bags[i].v] + bags[i].c);
			}
		}
		cout << "#" << tt << " " << dp[n][k] << "\n";
	}
}