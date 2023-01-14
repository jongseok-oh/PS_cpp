#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m;

bool map[1000][1000];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

void bfs(int y, int x) {
	queue<pii> q;
	q.push({ y,x });
	map[y][x] = true;
	while (q.size()) {
		pii t = q.front(); q.pop();
		int ty = t.first,
			tx = t.second;

		for (int dir = 0; dir < 4; dir++) {
			int ny = (ty + dy[dir] + n) % n,
				nx = (tx + dx[dir] + m) % m;
			if (!map[ny][nx]) {
				map[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];

	int cnt = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (!map[i][j]) {
			bfs(i, j); cnt++;
		}
	cout << cnt;
}