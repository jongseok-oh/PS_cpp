#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;

int map[1000][1000];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int ans[4];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	queue<pii> q;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> map[i][j];
		if (map[i][j] == 1 || map[i][j] == 2) q.push({i,j});
	}

	while (q.size()) {
		pii t = q.front(); q.pop();
		int y = t.first, x = t.second;
		int type = map[y][x] & 3;

		if (map[y][x] > 0 && type == 3) continue;

		int time = map[y][x] >> 2;
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir],
				nx = x + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (map[ny][nx] == -1 || (map[ny][nx]&3) == type) continue;
			if (map[ny][nx] == 0 || (map[ny][nx] >> 2) == time + 1)
			{
				map[ny][nx] |= ((time + 1) << 2);
				map[ny][nx]	|= type;
				q.push({ ny,nx });
			}
		}
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (map[i][j] > 0) ans[map[i][j] & 3]++;
	
	cout << ans[1] << " " << ans[2] << " " << ans[3];
}