#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;

string map[100];
string target;
int len;

int dp[100][100][80];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int solve(int idx, int y, int x) {
	if (idx == len) return 1;

	int& ret = dp[y][x][idx];

	if (ret != -1) return ret;

	ret = 0;

	for (int dir = 0; dir < 4; dir++) {
		for (int tk = 1; tk <= k; tk++) {
			int ny = y + dy[dir] * tk;
			int nx = x + dx[dir] * tk;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;

			if (map[ny][nx] == target[idx]) {
				ret += solve(idx + 1, ny, nx);
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) cin >> map[i];

	cin >> target;
	len = target.size();

	memset(dp, -1, sizeof dp);

	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (map[i][j] == target[0])
			ans += solve(1, i, j);
	}
	cout << ans;
}