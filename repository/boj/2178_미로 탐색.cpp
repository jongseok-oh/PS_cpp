#include <iostream>
#include <queue>
using namespace std;

int n, m;

string map[100];

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

struct loc{int y, x, depth;};

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>m;
	for (int i = 0; i < n; i++) cin >> map[i];
	
	queue<loc> q; q.push({ 0,0,1 });
	while (q.size()) {
		loc tl = q.front(); q.pop();
		int ty = tl.y, tx = tl.x, tdep = tl.depth;
		if (ty == (n - 1) && tx == (m - 1)) { cout << tl.depth; return 0;}
		map[ty][tx] = '0';

		for (int dir = 0; dir < 4; dir++) {
			int ny = ty + dy[dir],nx = tx + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (!(map[ny][nx] - '0')) continue;
			map[ny][nx] = '0';
			q.push({ ny,nx, tdep + 1 });
		}
	}
}