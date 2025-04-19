#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n,m;

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

char map[20][20];
bool visit[20][20][20][20];

vector<pii> coins;

struct coin
{
	pii c1, c2;
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> map[i][j];
		if (map[i][j] == 'o') coins.push_back({ i,j });
	}
	queue<coin> q; q.push({ coins[0], coins[1] });
	visit[coins[0].first][coins[0].second][coins[1].first][coins[1].second] = true;

	int ans = 0;
	while (q.size()) {
		if (ans >= 10) {
			cout << -1; return 0;
		}
		int qsize = q.size();
		while (qsize--) {
			coin t = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int outCnt = 0;
				pii nc1 = { t.c1.first + dy[dir], t.c1.second + dx[dir] };
				pii nc2 = { t.c2.first + dy[dir], t.c2.second + dx[dir] };

				if (nc1.first < 0 || nc1.first >= n || nc1.second < 0 || nc1.second >= m) outCnt++;
				else if (map[nc1.first][nc1.second] == '#') nc1 = t.c1;
				if (nc2.first < 0 || nc2.first >= n || nc2.second < 0 || nc2.second >= m) outCnt++;
				else if (map[nc2.first][nc2.second] == '#') nc2 = t.c2;

				if (outCnt == 1) {
					cout << ans + 1; return 0;
				}
				if (!outCnt && !visit[nc1.first][nc1.second][nc2.first][nc2.second]) {
					visit[nc1.first][nc1.second][nc2.first][nc2.second] = true;
					q.push({ nc1,nc2 });
				}
			}
		}
		ans++;
	}
	cout << -1;
}
