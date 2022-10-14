#include <iostream>
#include <vector>

using namespace std;

int n, k;

int map[13][13];

int dy[] = { -999,0,0,-1,1 }, dx[] = { -999,1,-1,0,0 };
int revdir[] = { -999,2,1,4,3};

struct chess { int y, x, dir;};

chess chesses[11];

bool isBlue(int y, int x) {
	if (y <= 0 || y > n || x <= 0 || x > n || map[y][x] == 2)
		return true;
	return false;
}

vector<int> info[13][13];

bool move(int no) {
	int y = chesses[no].y,
		x = chesses[no].x,
		dir = chesses[no].dir;

	int ny = y, nx = x;

	if (isBlue(y + dy[dir], x + dx[dir])) {
		dir = revdir[dir];
		chesses[no].dir = dir;
		if (!isBlue(y + dy[dir], x + dx[dir])) {
			ny += dy[dir];
			nx += dx[dir];
		}
	}
	else {
		ny += dy[dir];
		nx += dx[dir];
	}

	if (ny == y && nx == x) return false;

	int i = 0;
	for (; i < info[y][x].size(); i++)
		if (info[y][x][i] == no) break;
	
	vector<int> vec;
	if (map[ny][nx] == 1) {
		for (int j = info[y][x].size() - 1; j >= i; j--)
			vec.push_back(info[y][x][j]);
	}
	else {
		for (int j = i; j< info[y][x].size(); j++)
			vec.push_back(info[y][x][j]);
	}

	for (int _no : vec) {
		chesses[_no].y = ny;
		chesses[_no].x = nx;
	}

	for (int k = 0; k < vec.size(); k++)
		info[ny][nx].push_back(vec[k]);

	if (info[ny][nx].size() >= 4) return true;

	for (auto it = info[y][x].begin() + i; it != info[y][x].end();)
		it = info[y][x].erase(it);

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];
	
	for (int i = 1; i <=k; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		r; c; d;
		chesses[i] = { r,c,d };
		info[r][c].push_back(i);
	}

	int turn = 0;
	while (turn <= 1000) {
		turn++;
		for (int i = 1; i <=k; i++) {
			if (move(i)) {
				cout << turn; return 0;
			}
		}
		/*cout << "\nturn = " << turn << "\n";
		for (int i = 1; i <=n; i++) for (int j = 1; j <=n; j++) {
			if (info[i][j].size()) {
				cout << "i : " << i << " j : " << j << "\n";
				for (int k = 0; k < info[i][j].size(); k++)
					cout << info[i][j][k] << " ";
				cout << "\n";
			}
		}*/
	}
	cout << -1;
}