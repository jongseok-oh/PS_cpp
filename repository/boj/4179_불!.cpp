#include <iostream>
#include <queue>
using namespace std;

int n, m;

char maze[1000][1000];
bool visit[1000][1000] = { false, };

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

struct loc
{
	int y,x;
};

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>m;
	queue<loc> jihun, fire;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> maze[i][j];
		if (maze[i][j] == 'J') { jihun.push({ i,j }); maze[i][j] = '.'; }
		else if (maze[i][j] == 'F') fire.push({ i,j });
	}
	int time = 0;
	while (true) {
		int fSize = fire.size();
		while (fSize--) {
			loc tl = fire.front(); fire.pop();
			int fy = tl.y, fx = tl.x;
			for (int dir = 0; dir < 4; dir++) {
				int ny = fy + dy[dir], nx = fx + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (maze[ny][nx] == '.') {
					fire.push({ ny,nx }); maze[ny][nx] = 'F';
				}
			}
		}
		int jSize = jihun.size();
		while (jSize--) {
			loc tl = jihun.front(); jihun.pop();
			int jy = tl.y, jx = tl.x;
			visit[jy][jx] = true;
			for (int dir = 0; dir < 4; dir++) {
				int ny = jy + dy[dir], nx = jx + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) { cout << time + 1; return 0;}
				if (visit[ny][nx]) continue;
				if (maze[ny][nx] == '.') {
					jihun.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
		if (!jihun.size()) { cout << "IMPOSSIBLE"; return 0;}
		time++;
	}
	
}