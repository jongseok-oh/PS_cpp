#include <iostream>
#include <algorithm>

using namespace std;

int map[12][12];

struct Core
{
	int y, x;
}cores[12];

int n;

int coreCnt;

int maxCore, ans;

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

void makeLine(int& ny, int& nx, int& tlines, int dir) {
	while (ny >= 0 && ny < n && nx >= 0 && nx < n && !map[ny][nx]) {
		map[ny][nx] = 2;
		ny += dy[dir]; nx += dx[dir];
		tlines++;
	}
}

void removeLine(int y, int x, int idx, int dir) {
	while (y != cores[idx].y || x != cores[idx].x) {
		map[y][x] = 0;
		y += dy[dir]; x += dx[dir];
	}
}

int simulate(int select, int idx) {
	while (!(select & (1 << idx)) && idx < coreCnt) idx++;
	if (idx >= coreCnt) return 0;

	int ret = 500;

	for (int dir = 0; dir < 4; dir++) {
		int tlines = 0;

		int ny = cores[idx].y + dy[dir], nx = cores[idx].x + dx[dir];
		
		makeLine(ny, nx, tlines, dir);
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)
			ret = min(ret, tlines + simulate(select, idx + 1));

		removeLine(ny + dy[dir ^ 2], nx + dx[dir ^ 2], idx, dir ^ 2);
	}
	return ret;
}

// 조합
void solve(int idx, int select, int tcnt) {
	if (idx == coreCnt) return;
	if (idx != -1) {
		int tlines = simulate(select, 0);
		if (maxCore == tcnt)
			ans = min(ans, tlines);
		else if(maxCore < tcnt && tlines < 500){
			maxCore = tcnt;
			ans = tlines;
		}
	}
	for (int i = idx + 1; i < coreCnt; i++) {
		solve(i, select | (1 << i), tcnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n;
		coreCnt = 0, maxCore = 0, ans = 1e9;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] && i > 0 && i < n - 1 && j >0 && j < n - 1)
				cores[coreCnt++] = { i,j };
		}
		solve(-1, 0, 0);
		cout << "#" << tt << " " << ans << "\n";
	}
}