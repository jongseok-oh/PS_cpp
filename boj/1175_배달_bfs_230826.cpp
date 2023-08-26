#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

struct Loc { int y, x, pGift, pDir; };

vector<Loc> giftLoc;

char board[50][50];

bool visit[50][50][4][4];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	queue<Loc> q;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		cin >> board[i][j];
		
		if (board[i][j] == 'S') q.push({ i,j, 0,-1 }), board[i][j] = '.';
		else if (board[i][j] == 'C') giftLoc.push_back({ i,j}), board[i][j] = '.';
	}

	int ans = 0;

	while (q.size())
	{
		int qsize = q.size();

		while (qsize--)
		{
			Loc t = q.front(); q.pop();

			int y = t.y, x = t.x, pDir = t.pDir, pGift = t.pGift;

			for (int dir = 0; dir < 4; dir++) {
				if (dir == pDir) continue;
				int ny = y + dy[dir], nx = x + dx[dir];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == '#') continue;

				int nGift = pGift;

				for (int i = 0; i < 2; i++) {
					Loc& gift = giftLoc[i];
					if (gift.y == ny && gift.x == nx) {
						nGift |= (1 << i); break;
					}
				}

				if (nGift == 3) {
					cout << ++ans; return 0;
				}

				if (visit[ny][nx][dir][nGift]) continue;

				visit[ny][nx][dir][nGift] = true;

				q.push({ ny,nx,nGift, dir});
			}
		}

		++ans;
	}
	cout << -1;
}