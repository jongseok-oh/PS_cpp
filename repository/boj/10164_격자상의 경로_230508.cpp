#include <iostream>

using namespace std;

int n,m,k;

int dp[15][15];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>m>>k;

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (!i && !j) continue;
		dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
	}

	if (!k) { cout << dp[n - 1][m - 1]; return 0;}

	int r = (k - 1) / m, c = (k - 1) - r * m;

	int er = n - 1 - r, ec = m - 1 - c;

	cout << dp[r][c] * dp[er][ec];
}