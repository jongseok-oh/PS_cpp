#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

bool map[1000][1000];
bool visit[1000][1000];

int n, m, h, w, sr,sc,fr,fc;

int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
pii start[4];

bool chk(int dir, int ny, int nx) {
	ny += start[dir].first;
	nx += start[dir].second;
	if (ny < 0 || ny >= n || nx < 0 || nx >= m) return true;
	if (dir & 2) {
		for (int i = ny; i < ny + h; i++) 
			if (i >= n || map[i][nx]) return true;
	}
	else {
		for (int i = nx; i < nx + w; i++)
			if (i >= m || map[ny][i]) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	cin >> h >> w >> sr >> sc >> fr >> fc;
	sr--; sc--; fr--; fc--;

	start[1] = { h - 1, 0 };
	start[3] = { 0, w - 1 };

	map[sr][sc] = true;
	queue<pii> q; q.push({ sr,sc });

	int move = 0;

	while (q.size()) {
		int qsize = q.size();
		while (qsize--) {
			pii t = q.front(); q.pop();
			int y = t.first, x = t.second;
			if (y == fr && x == fc) {
				cout << move; return 0;
			}
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir],
					nx = x + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m || visit[ny][nx]) continue;
				if (chk(dir, ny, nx)) continue;
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
		move++;
	}
	cout << -1;
}