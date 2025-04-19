#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m, b;

int map[500][500];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> b;

	int _max = -1;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> map[i][j];
		_max = max(_max, map[i][j]);
	}

	int ans = 1e9, height = -1;
	int rTime = 0;
	vector<pii> maxBlock;
	while (_max >= 0) {
		int needBlock = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			if (map[i][j] == _max) maxBlock.push_back({ i,j });
			else {
				needBlock += _max - map[i][j];
			}
		}
		if (needBlock <= b) {
			if (ans > rTime + needBlock) {
				ans = rTime + needBlock;
				height = _max;
			}
		}
		rTime += maxBlock.size() * 2;
		b += maxBlock.size();
		for (auto& loc : maxBlock) {
			map[loc.first][loc.second]--;
		}
		_max--; maxBlock.clear();
	}
	cout << ans << " " << height;
}