#include <iostream>
#include <queue>

using namespace std;

int n, m;

char map[10][10];

struct loc
{
	int y, x;
};

struct bead {
	loc red, blue;
	int beforeDir = -1;
};
// 00,01,10,11
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	bead start;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> map[i][j];
		if (map[i][j] == 'B') { start.blue = { i,j }; map[i][j] = '.'; }
		else if (map[i][j] == 'R') { start.red = { i,j }; map[i][j] = '.';}
	}

	int ans = 0;
	queue<bead> q;
	q.push(start);
	
	while (q.size())
	{
		int qsize = q.size();

		while (qsize--) {
			bead t = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				// 지난 번에 반대방향에서 왔으면
				if ((dir ^ t.beforeDir) == 1) continue;

				// red move
				loc tRed = t.red;
				int redMovingCnt = 0;
				// 지금 구멍이 아니거나 다음 칸이 벽이 아닌 동안
				while (map[tRed.y][tRed.x] != 'O'
					&& map[tRed.y + dy[dir]][tRed.x + dx[dir]] != '#') {
					tRed.y += dy[dir];
					tRed.x += dx[dir];
					redMovingCnt++;
				}

				// blue move
				loc tBlue = t.blue;
				int blueMovingCnt = 0;
				// 지금 구멍이 아니거나 다음 칸이 벽이 아닌 동안
				while (map[tBlue.y][tBlue.x] != 'O'
					&& map[tBlue.y + dy[dir]][tBlue.x + dx[dir]] != '#') {
					tBlue.y += dy[dir];
					tBlue.x += dx[dir];
					blueMovingCnt++;
				}

				// 둘이 같은 위치인 경우
				if (tBlue.y == tRed.y && tBlue.x == tRed.x) {
					// 둘다 구멍에 빠졌다
					if (map[tBlue.y][tBlue.x] == 'O') continue;
					else {
						int mirrorDir = 1 ^ dir;
						// 더 많이 이동한 놈을 한칸 뒤로 움직인다.
						if (redMovingCnt > blueMovingCnt) {
							tRed.y += dy[mirrorDir];
							tRed.x += dx[mirrorDir];
						}
						else {
							tBlue.y += dy[mirrorDir];
							tBlue.x += dx[mirrorDir];
						}
					}
				}
				// 두 구슬이 다른 곳에 있음이 보장된다
				if (map[tBlue.y][tBlue.x] == 'O') continue;
				if (map[tRed.y][tRed.x] == 'O') {
					if (ans < 10) { cout << ans + 1; return 0; }
					else { cout << -1; return 0;}
				}

				q.push({ tRed, tBlue, dir });
			}
		}
		ans++;
		if (ans > 10) break;
	}
	cout << -1;
}