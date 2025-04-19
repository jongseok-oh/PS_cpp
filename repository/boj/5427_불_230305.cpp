#include <iostream>
#include <queue>

using namespace std;

int T;

struct loc
{
	int y, x;
};

char map[1000][1000];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		int n, m; cin >> m >> n;

		queue<loc> fire, sang;

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				fire.push({ i,j });
				map[i][j] = '#';
			}
			else if (map[i][j] == '@') {
				sang.push({ i,j });
			}
		}

		int ans = 0;
		bool flag = false;
		while (sang.size()) {
			int fqsize = fire.size();
			while (fqsize--) {
				loc t = fire.front(); fire.pop();

				for (int dir = 0; dir < 4; dir++) {
					int ny = t.y + dy[dir],
						nx = t.x + dx[dir];

					if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '#') continue;
					map[ny][nx] = '#';
					fire.push({ ny,nx });
				}
			}

			int sangSize = sang.size();
			while (sangSize--)
			{
				loc t = sang.front(); sang.pop();

				for (int dir = 0; dir < 4; dir++) {
					int ny = t.y + dy[dir],
						nx = t.x + dx[dir];

					if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
						flag = true; break;
					}
					if (map[ny][nx] != '.') continue;
					map[ny][nx] = '@';
					sang.push({ ny,nx });
				}
			}
			ans++;
			if (flag) {
				cout << ans<< "\n";
				break;
			}
		}
		if (!flag) cout << "IMPOSSIBLE" << "\n";
	}
}
