#include <iostream>
#include <queue>

using namespace std;

int n, m;

char board[10][10];
bool visit[100][100];

struct Loc {int y, x;};

bool setVisit(Loc red, Loc blue) {
	int rv = red.y * 10 + red.x;
	int bv = blue.y * 10 + blue.x;

	if (visit[rv][bv]) return false;

	visit[rv][bv] = true;
	return true;
}

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	Loc rLoc, bLoc;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 'R') rLoc = { i,j }, board[i][j] = '.';
		else if (board[i][j] == 'B') bLoc = { i,j }, board[i][j] = '.';
	}
	setVisit(rLoc, bLoc);

	queue<pair<Loc, Loc>> q;
	q.push({ rLoc, bLoc });
	
	int ans = 0;
	while (q.size())
	{
		int qsize = q.size();

		while (qsize--) {
			auto& rbLoc = q.front(); q.pop();

			int ry = rbLoc.first.y, rx = rbLoc.first.x;
			int by = rbLoc.second.y, bx = rbLoc.second.x;

			for(int dir = 0; dir<4; dir++){

				int nry = ry, nrx = rx;
				while (board[nry + dy[dir]][nrx + dx[dir]] != '#' && board[nry][nrx] != 'O')
					nry += dy[dir], nrx += dx[dir];

				int nby = by, nbx = bx;
				while (board[nby + dy[dir]][nbx + dx[dir]] != '#' && board[nby][nbx] != 'O')
					nby += dy[dir], nbx += dx[dir];

				// 빨간 구슬이 구멍에 빠짐
				if (board[nry][nrx] == 'O') {
					if (board[nby][nbx] == 'O') continue;

					cout << ++ans; return 0;
				}

				// 두 구슬이 같은 곳이 경우
				// 더 많이 움직인 구슬 한 칸 롤백
				if (nry == nby && nrx == nbx) {
					int rDist = abs(ry - nry) + abs(rx - nrx);
					int bDist = abs(by - nby) + abs(bx - nbx);

					if (rDist > bDist) nry -= dy[dir], nrx -= dx[dir];
					else nby -= dy[dir], nbx -= dx[dir];
				}

				Loc rLoc = { nry, nrx }, bLoc = { nby,nbx };
				// 이미 방문했으면
				if (!setVisit(rLoc, bLoc)) continue;

				q.push({ rLoc, bLoc });
			}
		}
		++ans;
	}

	cout << -1;
}