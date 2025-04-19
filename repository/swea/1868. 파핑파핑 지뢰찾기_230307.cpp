#include <iostream>
#include <cstring>

using namespace std;

int map[300][300];

int dy[] = { -1,-1,-1,0,1,1,1,0 }, dx[] = { -1,0,1,1,1,0,-1,-1};

int noBombCnt;
int n;

struct loc
{
	int y, x;
}q[90001];

int qf, qcnt;

void bfs(int y, int x) {

	map[y][x] = -1;
	noBombCnt--;

	q[qcnt++] = { y,x };
	while (qf != qcnt) {
		loc t = q[qf++];
		
		for (int dir = 0; dir < 8; dir++) {
			int ny = t.y + dy[dir],
				nx = t.x + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == -1) continue;

			if (!map[ny][nx]) q[qcnt++] = { ny, nx};
			map[ny][nx] = -1;
			noBombCnt--;
		}
	}
}

int main() {
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n;
		memset(map, 0, sizeof(map));
		noBombCnt = 0;
		qf = 0; qcnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			char data; cin >> data;
			if (data == '*') {
				for (int dir = 0; dir < 8; dir++) {
					int ny = i + dy[dir],
						nx = j + dx[dir];

					if (ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == -1) continue;
					map[ny][nx]++;
				}
				map[i][j] = -1;
			}
			else noBombCnt++;
		}

		int ans = 0;

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			if (!map[i][j]) {
				bfs(i, j); ans++;
			}
		}
		cout << "#" << tt << " " << ans + noBombCnt << "\n";
	}
}