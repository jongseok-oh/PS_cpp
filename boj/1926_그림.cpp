#include <iostream>
#include <queue>
using namespace std;

int n, m;

bool map[500][500];

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

struct loc{int y, x;};

int bfs(int y, int x) {
	queue<loc> q;
	q.push({ y,x });
	int cnt = 0;
	while (q.size()) {
		loc tl = q.front(); q.pop();
		y = tl.y, x = tl.x;
		map[y][x] = 0; cnt++;
		
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!map[ny][nx]) continue;
			q.push({ ny,nx }); map[ny][nx] = 0;
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];

	int maxArea = 0, cnt = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (map[i][j]) {
			int tArea = bfs(i, j); cnt++;
			maxArea = maxArea < tArea ? tArea : maxArea;
		}
	}
	cout << cnt << "\n" << maxArea;
}