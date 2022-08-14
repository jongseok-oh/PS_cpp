#include <iostream>
using namespace std;

int m, s;

int fdy[] = { 0,-1,-1,-1,0,1,1,1 }, fdx[] = { -1,-1,0,1,1,1,0,-1 };
// 방향이 같은 fish들을 따로 처리할 필요가 없음

int map[4][4][8], smell[4][4];
int sy, sx;

int fishSum[4][4];

int maxFishCnt;
int sdy[] = { -1,0,1,0 }, sdx[] = { 0,-1,0,1 };
int maxMovingStore[3];
int movingStore[3];

void sharkMove(int moveCnt, int fishCnt, int y, int x) {
	if (moveCnt == 3) {
		if (maxFishCnt < fishCnt) {
			for (int i = 0; i < 3; i++) maxMovingStore[i] = movingStore[i];
			maxFishCnt = fishCnt;
		}
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + sdy[dir], nx = x + sdx[dir];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
		int tFishCnt = fishSum[ny][nx];
		fishSum[ny][nx] = 0;
		movingStore[moveCnt] = dir;
		sharkMove(moveCnt + 1, fishCnt + tFishCnt, ny, nx);
		fishSum[ny][nx] = tFishCnt;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> s;
	while (m--) {
		int y, x, d;
		cin >> y >> x >> d;
		map[--y][--x][--d]++;
	}
	cin >> sy >> sx; sy--; sx--;

	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) smell[i][j] = -3;
	
	for (int time = 0; time < s; time++) {

		//1
		int copy[4][4][8];
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++) copy[i][j][d] = map[i][j][d];

		//2
		int move[4][4][8];
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++) move[i][j][d] = 0;
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++) {
			if (!map[i][j][d]) continue;

			int tDir = d;
			int nDir;
			for (int dir = 0; dir <= 8; dir++) {
				if (dir == 8) { move[i][j][d] += map[i][j][d]; break;}
				nDir = (tDir - dir + 8) % 8;
				int ny = i + fdy[nDir], nx = j + fdx[nDir];
				
				if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
				if (ny == sy && nx == sx) continue;
				if (time - smell[ny][nx] <= 2) continue;
				
				move[ny][nx][nDir] += map[i][j][d]; break;
			}
		}
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++)  map[i][j][d] = move[i][j][d];

		//3
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				fishSum[i][j] = 0;
				for (int d = 0; d < 8; d++)
					fishSum[i][j] += map[i][j][d];
			}

		maxFishCnt = -1;
		sharkMove(0, 0, sy, sx);

		for (int i = 0; i < 3; i++) {
			int dir = maxMovingStore[i];
			sy += sdy[dir], sx += sdx[dir];
			if (fishSum[sy][sx])
			{
				for (int d = 0; d < 8; d++) map[sy][sx][d] = 0;
				smell[sy][sx] = time;
			}
		}

		// 5
		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++) map[i][j][d] += copy[i][j][d];
	}
	long long answer = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int d = 0; d < 8; d++) answer += map[i][j][d];
	cout << answer;
}