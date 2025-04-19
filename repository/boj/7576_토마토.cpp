#include <iostream>
#include <queue>
using namespace std;

int n, m;

int tomato[1000][1000];

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

struct loc { int y,x;};

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m>>n;

	int unRiped = 0;
	queue<loc> q;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> tomato[i][j];
		if (tomato[i][j] == 1) q.push({ i,j });
		else if (tomato[i][j] == 0) unRiped++;
	}
	if (unRiped == 0) { cout << 0; return 0;}
	
	int day = 0;
	while (true) {

		int size = q.size();
		bool spread = false;
		while (size--) {
			loc tl = q.front(); q.pop();

			int y = tl.y, x = tl.x;
			
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (!tomato[ny][nx]) {
					q.push({ ny,nx }); tomato[ny][nx] = 1;
					unRiped--; spread = true;
				}
			}
		}
		
		if (!spread) {
			if (unRiped) cout << "-1";
			else cout << day;
			return 0;
		}
		day++;
	}
}