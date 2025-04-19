#include <iostream>
#include <cstring>

using namespace std;

int map[1000][1000];

int n, m;

int dp[1000][1000];

int dy[] = { 1,0,1 }, dx[] = { 0,1,1 };

int solve(int y, int x) {
	if (y == n - 1 && x == m - 1) return map[y][x];
	int& ret = dp[y][x];
	if (ret != -1) return ret;

	ret = 0;

	for (int dir = 0; dir < 3; dir++) {
		int ny = y + dy[dir],
			nx = x + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		
		ret = max(ret, solve(ny, nx) + map[y][x]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> map[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
	
}