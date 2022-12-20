#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int r, c;

char map[50][50];
bool visit[50][50];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;

	queue<pii> water;
	queue<pii> dochi;

	for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
		cin >> map[i][j];
		if (map[i][j] == 'S') {
			dochi.push({ i,j });
			map[i][j] = '.';
		}
		else if (map[i][j] == '*') water.push({ i,j});
	}

	int time = 0;
	bool find = false;
	
	while (dochi.size()) {
		int wqsize = water.size();
		while (wqsize--) {
			pii t = water.front(); water.pop();
			
			for (int dir = 0; dir < 4; dir++) {
				int ny = t.first + dy[dir],
					nx = t.second + dx[dir];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (map[ny][nx] == 'D' || map[ny][nx] == 'X' || map[ny][nx] == '*') continue;
				water.push({ ny,nx }); map[ny][nx] = '*';
			}
		}

		int dqsize = dochi.size();
		while (dqsize--) {
			pii t = dochi.front(); dochi.pop();
			if (map[t.first][t.second] == 'D') {
				find = true; break;
			}
			//if (map[t.first][t.second] == '*') continue;
			
			for (int dir = 0; dir < 4; dir++) {
				int ny = t.first + dy[dir],
					nx = t.second + dx[dir];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (visit[ny][nx] ||map[ny][nx] == 'X' || map[ny][nx] == '*') continue;
				dochi.push({ ny,nx });
				visit[ny][nx] = true;
			}
		}
		if (find) break;
		time++;
	}
	if (find) cout << time;
	else cout << "KAKTUS";
}