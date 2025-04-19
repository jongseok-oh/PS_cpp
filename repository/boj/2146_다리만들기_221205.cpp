#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n;

int map[100][100];
bool visit[100][100][5050];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

struct info
{
	int y, x, num;
};

queue<info> iq;
void markIsland(int y, int x, int iNum) {
	iq.push({ y,x, iNum });
	
	queue<pii> q; q.push({ y,x });

	map[y][x] = iNum;

	while (q.size()) {
		pii t = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = t.first + dy[dir],
				nx = t.second + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (map[ny][nx] == 1) {
				map[ny][nx] = iNum;
				q.push({ ny,nx });
				iq.push({ ny,nx,iNum });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];
	
	int islandNum = 2;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (map[i][j] == 1) markIsland(i, j, islandNum++);
	}

	int bridge = 0;
	bool find = false;

	while (iq.size()) {
		int qsize = iq.size();
		while (qsize--) {
			info t = iq.front(); iq.pop();
			
			for (int dir = 0; dir < 4; dir++) {
				int ny = t.y + dy[dir],
					nx = t.x + dx[dir];

				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (visit[ny][nx][t.num] || map[ny][nx] == t.num) continue;
				if (map[ny][nx] == 0) {
					visit[ny][nx][t.num] = true; iq.push({ ny,nx,t.num });
				}
				else {
					find = true; break;
				}
			}
			if (find) break;
		}
		if (find) break;
		bridge++;
	}
	cout << bridge;
}