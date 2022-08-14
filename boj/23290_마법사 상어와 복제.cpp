#include <iostream>
#include <vector>
using namespace std;

int m, s;

int fdy[] = { 0,-1,-1,-1,0,1,1,1 }, fdx[] = { -1,-1,0,1,1,1,0,-1 };

struct fish {
	int y, x, d;
};

vector<fish> map[5][5];
int smell[5][5];

int sy, sx;
int sdy[] = { -1,0,1,0 }, sdx[] = { 0,-1,0,1 };
string sMove;
string maxMove;
int maxFishCnt;
int fishCntMap[5][5];
void sharkMove(int cnt, int y, int x, int fishCnt) {
	if (cnt == 3) {
		if (maxFishCnt < fishCnt || (maxFishCnt == fishCnt && sMove < maxMove)) {
			maxFishCnt = fishCnt; maxMove = sMove;
		}
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + sdy[dir],
			nx = x + sdx[dir];
		if (ny < 1 || ny>4 || nx < 1 || nx>4) continue;
		sMove[cnt] = dir + '0';
		int tfishCnt = fishCntMap[ny][nx];
		fishCntMap[ny][nx] = 0;
		sharkMove(cnt + 1, ny, nx, fishCnt + tfishCnt);
		fishCntMap[ny][nx] = tfishCnt;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> s;

	while (m--) {
		int x, y, d;
		cin >> y >> x >> d;
		map[y][x].push_back({ y,x,--d });
	}
	cin >> sy >> sx;

	for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++) smell[i][j] = -3;
	
	for (int time = 0; time < s; time++) {
		vector<fish> copyFish[5][5];
		
		// 1
		for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++) copyFish[i][j] = map[i][j];

		// 2
		vector<fish> moveMap[5][5];
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				vector<fish> tfs = map[i][j];
				for (auto it = tfs.begin(); it != tfs.end(); it++) {
					fish tf = *it;

					bool move = false;
					int td = tf.d;
					int nd;
					for (int dir = 0; dir <=8; dir++) {
						nd = (td - dir + 8) % 8;
						int ny = i + fdy[nd],
							nx = j + fdx[nd];
						if (ny < 1 || ny>4 || nx < 1 || nx > 4) continue;
						if (ny == sy && nx == sx) continue;
						if (time - smell[ny][nx] <=2) continue;

						moveMap[ny][nx].push_back({ny,nx,nd});
						move = true;
						break;
					}
					// 안 움직였음 moveMap에 추가
					if(!move) moveMap[i][j].push_back(tf);
				}
			}
		}
		for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++) map[i][j] = moveMap[i][j];
		
		// 3
		sMove = "555";
		maxFishCnt = -1;

		for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++) fishCntMap[i][j] = map[i][j].size();

		sharkMove(0, sy, sx, 0);
		for (int i = 0; i < 3; i++) {
			int dir = maxMove[i] - '0';
			sy += sdy[dir];
			sx += sdx[dir];
			if (map[sy][sx].size())
			{
				map[sy][sx].clear();
				smell [sy] [sx] = time;
			}
		}

		//4
		for(int i =1; i<=4; i++)
			for (int j = 1; j <= 4; j++)
			{
				vector<fish> cf = copyFish[i][j];
				for (int k = 0, len = cf.size(); k < len; k++)
					map[i][j].push_back(cf[k]);
			}
	}
	long long answer = 0;
	for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++) answer += map[i][j].size();
	cout << answer;
}