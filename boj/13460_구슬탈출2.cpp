#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

string map[10];

struct loc {
	int ry, rx, by, bx, pdir = -1;
};

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int dircontinue[] = { 1,0,3,2 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	loc start;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'R') {
				start.ry = i; start.rx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				start.by = i; start.bx = j;
				map[i][j] = '.';
			}
		}
	}

	queue<loc> q; q.push(start);

	int move = 0;

	while (q.size()) {
		int qsize = q.size();
		if (move > 10) break;
		while (qsize--) {
			loc t = q.front(); q.pop();
			int ry = t.ry, rx = t.rx,
				by = t.by, bx = t.bx,
				pdir = t.pdir;

			if (map[ry][rx] == 'O') {
				cout << move; return 0;
			}

			for (int dir = 0; dir < 4; dir++) {

				if (pdir != -1) 
					if (dircontinue[dir] == pdir) continue;
				

				int nry = ry, nrx = rx,
					nby = by, nbx = bx;

				// blue move
				while (map[nby + dy[dir]][nbx + dx[dir]] != '#'
					&& map[nby][nbx] != 'O') {
					nby += dy[dir]; nbx += dx[dir];
				}
				if (map[nby][nbx] == 'O') continue;

				// red move
				while (map[nry + dy[dir]][nrx + dx[dir]] != '#'
					&&map[nry][nrx] != 'O') {
					nry += dy[dir]; nrx += dx[dir];
				}

				if (nry == nby && nrx == nbx) {
					int rlen = abs(nry - ry) + abs(nrx - rx);
					int blen = abs(nby - by) + abs(nbx - bx);

					if (rlen > blen) {
						nry -= dy[dir];
						nrx -= dx[dir];
					}
					else {
						nby -= dy[dir];
						nbx -= dx[dir];
					}
				}
				q.push({ nry,nrx,nby,nbx, dir});
			}
		}
		move++;
	}
	cout << -1;
}