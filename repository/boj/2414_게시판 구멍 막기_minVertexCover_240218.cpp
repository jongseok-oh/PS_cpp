#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n, m;

string map[50];

int rowNum = 1, colNum = 1;
int rowLine[50][50], colLine[50][50];

vector<int> con[2500];

void makeLine() {
	for (int y = 0; y < n; ++y) {
		int x = 0;
		while (x < m) {
			while (x < m && map[y][x] == '.') x++;
			while (x < m && map[y][x] == '*') {
				colLine[y][x] = colNum;
				x++;
			}
			++colNum;
		}
	}

	for (int x = 0; x < m; ++x) {
		int y = 0;
		while (y < n) {
			while (y < n && map[y][x] == '.') y++;
			while (y < n && map[y][x] == '*') {
				rowLine[y][x] = rowNum;
				y++;
			}
			++rowNum;
		}
	}
}

bool visit[2500];
int colMatch[2500];
bool dfs(int row) {
	if (visit[row]) return false;
	visit[row] = true;
	for (int col : con[row]) {
		if (colMatch[col] == -1 || dfs(colMatch[col])) {
			colMatch[col] = row;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> map[i];

	makeLine();

	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
		if (map[i][j] == '*') con[rowLine[i][j]].push_back(colLine[i][j]);

	memset(colMatch, -1, 4 * colNum);

	int ret = 0;
	for (int i = 0; i < rowNum; ++i) {
		memset(visit, 0, rowNum);
		if (dfs(i)) ++ret;
	}
	cout << ret;
}