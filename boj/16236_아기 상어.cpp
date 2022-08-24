#include <iostream>
#include <queue>

using namespace std;

int n;

int map[20][20];
bool visit[20][20];

int sy, sx;
int sSize = 2;

int eatCnt = 0;

struct loc { int y, x;};

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

bool check() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (map[i][j] != 0 && map[i][j] < sSize) return true;
	}
	return false;
}

int eat() {
	visit[sy][sx] = true;
	queue<loc> q; q.push({ sy,sx });
	
	int dist = 0;
	bool find = false;

	int nsy = 38, nsx = 38;
	while (q.size()) {
		int size = q.size();
		while (size--) {
			loc tloc = q.front(); q.pop();
			int y = tloc.y, x = tloc.x;

			if (map[y][x] != 0 && map[y][x] < sSize) {
				find = true;
				if (y < nsy || (y == nsy && x < nsx)) {
					nsy = y; nsx = x;
				}
			}
			
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir], nx = x + dx[dir];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (visit[ny][nx]) continue;
				if (map[ny][nx] > sSize) continue;
				
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
		if (find)break;
		dist++;
	}
	if (nsy == 38) return -1;
	sy = nsy; sx = nsx;
	map[sy][sx] = 0;
	return dist;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> map[i][j];
		if (map[i][j] == 9) {
			sy = i; sx = j;
			map[sy][sx] = 0;
		}
	}

	int time = 0;
	while (true) {
		if (!check()) {
			break;
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) visit[i][j] = false;
		int dist = eat();
		if (dist == -1) break;
		time += dist;
		eatCnt++;
		if (eatCnt == sSize) {
			sSize++; eatCnt = 0;
		}
	}
	cout << time;
}