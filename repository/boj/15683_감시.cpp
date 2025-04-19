#include <iostream>
#include <vector>

using namespace std;

int n, m;

int map[8][8];
int _copy[8][8];

int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };

struct cctv {
	int y, x, type;
};

vector<cctv> cctvs;

vector<int> cctvDir[] = { {},{0},{1},{2},{3},
	{0,2},{1,3},
	{3,0},{0,1},{1,2},{2,3},
	{2,3,0},{3,0,1},{0,1,2},{1,2,3},
	{0,1,2,3}
};

int cctvCnt;

int _min = 1e9;

void Print() {
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << _copy[i][j] << " ";
		cout << "\n";
	}
}

void dfs(int idx) {
	if (idx == cctvCnt) {
		vector<cctv> tcctv;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			_copy[i][j] = map[i][j];
			if (_copy[i][j] != 0 && _copy[i][j] != 38) tcctv.push_back({ i,j,_copy[i][j]});
		}
		for (auto ttv : tcctv) {
			int y = ttv.y, x = ttv.x;
			_copy[y][x] = -1;
			for (int dir : cctvDir[ttv.type]) {
				int ny = y + dy[dir], nx = x + dx[dir];
				while (ny >= 0 && ny < n && nx >= 0 && nx < m && _copy[ny][nx] != 38) {
					_copy[ny][nx] = -1;
					ny += dy[dir]; nx += dx[dir];
				}
			}
		}
		//Print();
		int sum = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!_copy[i][j]) sum++;
		_min = _min > sum ? sum : _min;
		return;
	}
	
	for (int i = idx; i < cctvCnt; i++) {
		int y = cctvs[i].y, x = cctvs[i].x;
		switch (cctvs[i].type) {
			case 1:
				map[y][x] = 1;
				dfs(i + 1);
				map[y][x] = 2;
				dfs(i + 1);
				map[y][x] = 3;
				dfs(i + 1);
				map[y][x] = 4;
				dfs(i + 1);
				break;
			case 2:
				map[y][x] = 5;
				dfs(i + 1);
				map[y][x] = 6;
				dfs(i + 1);
				break;
			case 3:
				map[y][x] = 7;
				dfs(i + 1);
				map[y][x] = 8;
				dfs(i + 1);
				map[y][x] = 9;
				dfs(i + 1);
				map[y][x] = 10;
				dfs(i + 1);
				break;
			case 4:
				map[y][x] = 11;
				dfs(i + 1);
				map[y][x] = 12;
				dfs(i + 1);
				map[y][x] = 13;
				dfs(i + 1);
				map[y][x] = 14;
				dfs(i + 1);
				break;
			case 5:
				map[y][x] = 15;
				dfs(i + 1);
				break;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		cin >> map[i][j];
		if (map[i][j] == 6) map[i][j] = 38;
		if(map[i][j] != 0 && map[i][j] != 38) cctvs.push_back({ i,j,map[i][j]});
	}
	cctvCnt = cctvs.size();
	dfs(0);
	cout << _min;
}