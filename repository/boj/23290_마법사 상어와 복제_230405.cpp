#include <iostream>
#include <cstring>

using namespace std;

int m, s;

int dy[] = { 0,-1,-1,-1,0,1,1,1 },
dx[] = { -1,-1,0,1,1,1,0,-1 };

int map[4][4][8];
int copy_map[4][4][8];
int smell[4][4];

int sharkY, sharkX;

void copyMap() {
	for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
		copy_map[i][j][d] = map[i][j][d];
}

int tempMoveMap[4][4][8];
void fishMove() {
	memset(tempMoveMap, 0, sizeof(tempMoveMap));

	for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++) {
		// 물고기가 존재하면
		if (map[i][j][d]) {
			int nextDir = d;
			int ny = i, nx = j;

			bool find = false;
			// 45도 회전 회전
			for (int k = 0; k < 8; k++) {
				nextDir = (d - k + 8) % 8;
				ny = i + dy[nextDir];
				nx = j + dx[nextDir];

				if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4
					|| (ny == sharkY && nx == sharkX)
					|| smell[ny][nx] >0) continue;

				find = true; break;
			}
			if (find) tempMoveMap[ny][nx][nextDir] += map[i][j][d];
			else tempMoveMap[i][j][d] += map[i][j][d];
		}
	}

	for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
		map[i][j][d] = tempMoveMap[i][j][d];
}

int sharkDy[] = { -1,0,1,0 }, sharkDx[] = { 0,-1,0,1 };

int maxFishCnt;
int tPath[3];
int ansPath[3];

bool visit[4][4];

int getFish(int y, int x, int idx) {
	if (idx == 3) return 0;
	int ny = y + sharkDy[tPath[idx]];
	int nx = x + sharkDx[tPath[idx]];

	if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) return -1e8;

	int ret = 0;

	if (!visit[ny][nx]) for (int d = 0; d < 8; d++) ret += map[ny][nx][d];
	visit[ny][nx] = true;
	ret += getFish(ny, nx, idx + 1);
	visit[ny][nx] = false;

	return ret;
}

void makeSharkPath(int idx) {

	if (idx == 3) {
		int catchFish = getFish(sharkY, sharkX, 0);
		if (catchFish > maxFishCnt) {
			maxFishCnt = catchFish;
			for (int i = 0; i < 3; i++) ansPath[i] = tPath[i];
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		tPath[idx] = dir;
		makeSharkPath(idx + 1);
	}
}

void sharkMove() {
	maxFishCnt = -1;
	// 물고기를 제일 많이 잡는 방법이
	// ansPath에 적힌다.
	makeSharkPath(0);

	// 실제로 이동하며 물고기를 잡고 냄새를 남긴다
	for (int i = 0; i < 3; i++) {
		sharkY += sharkDy[ansPath[i]];
		sharkX += sharkDx[ansPath[i]];

		for (int d = 0; d < 8; d++)
			if (map[sharkY][sharkX][d]) {
				map[sharkY][sharkX][d] = 0;
				smell[sharkY][sharkX] = 3;
			}
	}
}

void eraseSmell() {
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) smell[i][j]--;
}

void realCopy() {
	for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
		map[i][j][d] += copy_map[i][j][d];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		int y, x, d; cin >> y >> x >> d;
		y--; x--; d--;
		map[y][x][d]++;
	}
	cin >> sharkY >> sharkX;
	sharkY--; sharkX--;
	while (s--) {
		// no.1
		copyMap();

		//  ←, ↖, ↑, ↗, →, ↘, ↓, ↙
		// no.2
		fishMove();

		// no.3
		sharkMove();

		// no.4
		eraseSmell();

		//no.5
		realCopy();
	}

	// 마법 종료 후 모든 물고기의 합
	//  ←, ↖, ↑, ↗, →, ↘, ↓, ↙

	int ans = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)
		ans += map[i][j][d];
	cout << ans;
}