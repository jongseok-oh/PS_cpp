#include <iostream>
#include <cstring>

using namespace std;

int n, m;

int map[300][300];
int copyMap[300][300];

bool visit[300][300];

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

void dfs(int y, int x) {
	visit[y][x] = true;

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir],
			nx = x + dx[dir];
		if (ny <= 0 || ny >= n - 1 || nx <= 0 || nx >= m - 1
			|| visit[ny][nx] || map[ny][nx] <= 0) continue;
		dfs(ny, nx);
	}
}

bool gflag = true;

bool isDivide() {
	
	memset(visit, 0, sizeof(visit));

	bool flag = false;

	for (int i = 1; i < n - 1; i++) for (int j = 1; j < m - 1; j++) {
		if (map[i][j] > 0 && !visit[i][j]) {
			if (flag) return true;
			dfs(i, j);
			flag = true;
		}
	}
	gflag = flag;
	return false;
}

void copy(int map[][300], int copyMap[][300]) {
	for (int i = 1; i < n - 1; i++) for (int j = 1; j < m - 1; j++)
		copyMap[i][j] = map[i][j];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> map[i][j];
		copyMap[i][j] = map[i][j];
	}

	int ans = 0;
	while (gflag)
	{
		if (isDivide()) {
			cout << ans; return 0;
		}

		for (int i = 1; i < n - 1; i++) for (int j = 1; j < m - 1; j++) {
			if (map[i][j] > 0) {
				for (int dir = 0; dir < 4; dir++) {
					int ny = i + dy[dir],
						nx = j + dx[dir];
					if (map[ny][nx] <= 0) copyMap[i][j]--;
				}
			}
		}
		ans++;
		copy(copyMap, map);
	}
	cout << 0;
}