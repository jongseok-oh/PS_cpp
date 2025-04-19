#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int _max = -1;

void rotate(vector<vector<int>>& map) {
	vector<vector<int>> tmap(n, vector<int>(n));

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		tmap[j][n - 1 - i] = map[i][j];
	}
	map = tmap;
}

void move(vector<vector<int>>& map) {
	vector<vector<bool>> change(n, vector<bool>(n, false));

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				int ty = i;
				while (ty + 1 < n && !map[ty + 1][j]) ty++;
				
				map[ty][j] = map[i][j];

				if (ty != i) map[i][j] = 0;

				if (ty < n - 1 && !change[ty + 1][j]
					&& map[ty + 1][j] == map[ty][j]) {
					map[ty + 1][j] = map[ty][j] * 2;
					map[ty][j] = 0;
					change[ty + 1][j] = true;
				}
			}
		}
	}
}

void solve(const vector<vector<int>>& map, int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
			_max = max(_max, map[i][j]);
		return;
	}

	for (int rot = 0; rot < 4; rot++) {
		vector<vector<int>> tmap = map;
		for (int j = 0; j < rot; j++) rotate(tmap);
		move(tmap);
		solve(tmap, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];

	solve(map, 0);
	cout << _max;
}