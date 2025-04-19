#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

char map[50][50];

struct loc
{
	int y, x;
}q[3000];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int charLen = 'W' - 'A';

int getMaxLen(int y, int x) {
	
	int ret = -1, front = 0, qcnt = 0;
	q[qcnt++] = { y,x };

	char tar = map[y][x];
	char nChar = (map[y][x] - 'A' + 1) % charLen + 'A';

	map[y][x] = nChar;

	while (front != qcnt) {

		int tqcnt = qcnt - front;
		
		while (tqcnt--)
		{
			loc t = q[front++];

			for (int dir = 0; dir < 4; dir++) {
				int ny = t.y + dy[dir],
					nx = t.x + dx[dir];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (map[ny][nx] == tar) {
					map[ny][nx] = nChar;
					q[qcnt++] = { ny,nx };
				}
			}
		}
		ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	
	int ans = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (map[i][j] != 'W') {
			ans = max(ans, getMaxLen(i, j));
		}
	}
	cout << ans;
}