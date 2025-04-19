#include <iostream>
#include <cstring>

using namespace std;

int m, s, sy, sx;

int dy[] = { 0,-1,-1,-1,0,1,1,1 }, dx[] = { -1,-1,0,1,1,1,0,-1 };
int sdy[] = { -1,0,1,0 }, sdx[] = { 0,-1,0, 1};

int map[4][4][8], tmap[4][4][8];
int mmap[4][4][8];
int smell[4][4];

int _max;
int move_trace[3];
int t_trace[3];

bool eaten[4][4];

void sharkMove(int y, int x, int cnt, int eat) {
	if (cnt == 3) {
		if (eat > _max) {
			_max = eat;
			for (int i = 0; i < 3; i++) move_trace[i] = t_trace[i];
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int ny = y + sdy[dir],
			nx = x + sdx[dir];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;

		t_trace[cnt] = dir;
		if (eaten[ny][nx]) {
			sharkMove(ny, nx, cnt + 1, eat);
		}
		else {
			int fishCnt = 0;
			for (int d = 0; d < 8; d++) fishCnt += map[ny][nx][d];
			eaten[ny][nx] = true;
			sharkMove(ny, nx, cnt + 1, eat + fishCnt);
			eaten[ny][nx] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> s;

	for (int i = 0; i < m; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		r--; c--; d--;
		map[r][c][d]++;
	}

	cin >> sy >> sx;
	sy--; sx--;

	while (s--) {

		// 1.
		memset(tmap, 0, sizeof(tmap));
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
			tmap[i][j][d] = map[i][j][d];

		
		// 2.
		memset(mmap, 0, sizeof(mmap));
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++) {
			if (map[i][j][d]) {
				int ndir, ny, nx;
				bool find = false;
				for (int dm = 0; dm < 8; dm++) {
					ndir = (d - dm + 8) % 8;
					ny = i + dy[ndir];
					nx = j + dx[ndir];
					if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
					if (ny == sy && nx == sx) continue;
					if (smell[ny][nx] > 0) continue;
					find = true; break;
				}
				if (find) mmap[ny][nx][ndir] += map[i][j][d];
				else mmap[i][j][d] += map[i][j][d];
			}
		}
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
			map[i][j][d] = mmap[i][j][d];

		// 3.
		_max = -1;
		memset(eaten, 0, sizeof(eaten));
		sharkMove(sy, sx, 0, 0);

		for (int i = 0; i < 3; i++) {
			int tdir = move_trace[i];
			sy += sdy[tdir]; sx += sdx[tdir];
			for (int dd = 0; dd < 8; dd++) {
				int teat = map[sy][sx][dd];
				if (teat != 0) smell[sy][sx] = 3;
				map[sy][sx][dd] = 0;
			}
		}

		// 4.
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) smell[i][j]--;

		// 5.
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
			map[i][j][d] += tmap[i][j][d];
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
		ans += map[i][j][d];
	cout << ans;
}