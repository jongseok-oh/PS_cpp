#include <iostream>
#include <vector>
using namespace std;

struct Loc {int y, x;};

vector<Loc> emptyLoc;
vector<Loc> teacherLoc;

int n;
const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
char map[6][6];

bool isIn(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

bool simulation() {
	for (Loc& loc : teacherLoc) {
		
		for (int dir = 0; dir < 4; ++dir) {
			int ny = loc.y + dy[dir];
			int nx = loc.x + dx[dir];

			while (isIn(ny, nx) && map[ny][nx] != 'O' && map[ny][nx] != 'S') {
				ny += dy[dir];
				nx += dx[dir];
			}

			if (isIn(ny, nx) && map[ny][nx] == 'S') return false;
		}
	}
	return true;
}

bool solve(int emptyIdx, int wallCnt) {
	if (wallCnt == 3) {
		return simulation();
	}
	if (emptyIdx == emptyLoc.size()) return false;

	for (int i = emptyIdx; i < emptyLoc.size(); ++i) {
		int y = emptyLoc[i].y;
		int x = emptyLoc[i].x;

		map[y][x] = 'O';
		if (solve(i + 1, wallCnt + 1)) return true;
		map[y][x] = 'X';
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> map[i][j];
		if (map[i][j] == 'X')
			emptyLoc.push_back({ i,j });
		else if (map[i][j] == 'T')
			teacherLoc.push_back({ i,j });
	}

	cout << (solve(0, 0) ? "YES" : "NO");
}