#include <iostream>
#include <cstring>

using namespace std;

int c, n, m;

int dp[10][1 << 10][1<<10];

string map[10];

bool cantSit(int t,int row,int uVisit, int tVisit) {
	return map[row][t] == 'x' || (tVisit & (1 << t)) || (tVisit & (1 << (t + 1)))
		|| (tVisit & (1 << (t - 1))) || (uVisit & (1 << (t - 1))) || (uVisit & (1 << (t + 1)));
}

int solve(int row, int uVisit, int tVisit, int start) {
	if (row == -1) return 0;
	int& ret = dp[row][uVisit][tVisit];
	if (ret != -1) return ret;
	ret = max(ret, solve(row - 1, tVisit, 0, 0));

	for (int i = start; i < m; i++) {
		if (!cantSit(i, row, uVisit, tVisit))
			ret = max(ret, solve(row, uVisit, tVisit | (1 << i), i + 1) + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> map[i];
		memset(dp, -1, sizeof(dp));
		cout << solve(n - 1, 0, 0,0) << "\n";
	}
}