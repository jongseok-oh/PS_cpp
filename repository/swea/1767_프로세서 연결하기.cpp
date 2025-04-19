#include <iostream>

using namespace std;

int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };

int n;

int map[12][12];

bool visit[12];

int _maxCore, _minLen;

struct loc { int y, x; };

loc cores[12];

int coreCnt;

void copyMap(int map[12][12], int tempMap[12][12]) {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		tempMap[i][j] = map[i][j];
}

void solve(int tCoreCnt, int tLen, int tMap[12][12], int idx) {
	if (tCoreCnt > _maxCore) {
		_maxCore = tCoreCnt; _minLen = tLen;
	}
	else if (tCoreCnt == _maxCore) {
		if (_minLen > tLen) {
			_minLen = tLen;
		}
	}

	for (int i = idx; i < coreCnt; i++) {
		if (visit[i]) continue;
		int y = cores[i].y, x = cores[i].x;
		for (int dir = 0; dir < 4; dir++) {
			int tempMap[12][12];
			copyMap(tMap, tempMap);
			bool connect = true;

			int ny = y, nx = x;
			int len = 0;
			while (ny + dy[dir] >= 0 && ny + dy[dir] < n && nx + dx[dir] >= 0 && nx + dx[dir] < n) {
				ny += dy[dir]; nx += dx[dir]; 
				if (tempMap[ny][nx]) { connect = false; break;}
				tempMap[ny][nx] = -1; len++;
			}
			if (connect) {
				visit[i] = true;
				solve(tCoreCnt + 1, tLen + len, tempMap, i+1);
				visit[i] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		
		for (int i = 0; i < n; i++) visit[i]=false;

		coreCnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				cores[coreCnt] = { i,j};
				if (i == 0 || i == n - 1 || j == 0 || j == n - 1) visit[coreCnt] = true;
				coreCnt++;
			}
		}
		_maxCore = -1; _minLen = 1e9;
		solve(0,0,map,0);
		cout << "#" << tc << " " << _minLen << "\n";
	}
}