#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

bool map[100][100];

int leftNum = 0, rightNum = 0;
int leftLine[100][100], rightLine[100][100];

vector<int> con[1000];

void makeLeftLine(int y, int x) {
	while (x >= 0 && y < n) {
		while (x >= 0 && y < n && map[y][x]) {
			y++; x--;
		}
		while (x >= 0 && y < n && !map[y][x]) {
			leftLine[y][x] = leftNum;
			y++; x--;
		}
		leftNum++;
	}
}

void makeRightLine(int y, int x) {
	while (x < n && y < n) {
		while (x < n && y < n && map[y][x]) {
			y++; x++;
		}
		while (x < n && y < n && !map[y][x]) {
			rightLine[y][x] = rightNum;
			y++; x++;
		}
		rightNum++;
	}
}

void makeLine() {
	for (int i = 0; i < n; ++i)
		makeLeftLine(0, i);
	for (int i = 1; i < n; ++i)
		makeLeftLine(i, n - 1);

	for (int i = 0; i < n; ++i)
		makeRightLine(0, i);
	for (int i = 1; i < n; ++i)
		makeRightLine(i, 0);
}

bool visit[1000];
int rightMatch[1000];
bool dfs(int left) {
	if (visit[left]) return false;
	visit[left] = true;

	for (int right : con[left]) {
		if (rightMatch[right] == -1 || dfs(rightMatch[right])) {
			rightMatch[right] = left;
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	int y, x;
	for (int i = 0; i < m; ++i) {
		cin >> y >> x;
		map[--y][--x] = true;
	}
	makeLine();

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
		if (!map[i][j]) con[leftLine[i][j]].push_back(rightLine[i][j]);


	memset(rightMatch, -1, rightNum * 4);

	int ret = 0;
	for (int i = 0; i < leftNum; ++i) {
		memset(visit, 0, leftNum);
		if (dfs(i)) ret++;
	}

	cout << ret;
}