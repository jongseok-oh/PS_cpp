#include <iostream>
#include <queue>

using namespace std;

int N,M,H;
int tomato[100][100][100];

struct Loc { int z, y, x;};

int dy[] = { 1,0,-1,0,0,0 }, dx[] = { 0,1,0,-1,0,0 }, dz[] = { 0,0,0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> H;

	queue<Loc> q;
	int noRipeCnt = 0;
	for (int h = 0; h < H; h++) for (int m = 0; m < M; m++) for (int n = 0; n < N; n++)
	{
		cin >> tomato[h][m][n];

		int tToma = tomato[h][m][n];
		if (tToma == 1) q.push({ h,m,n });
		else if (tToma == 0) ++noRipeCnt;
	}

	if (noRipeCnt == 0) {
		cout << 0; return 0;
	}

	int day = 0;

	while (noRipeCnt && q.size())
	{
		int qsize = q.size();

		while (qsize--) {
			Loc tLoc = q.front(); q.pop();

			int z = tLoc.z, x = tLoc.x, y = tLoc.y;

			for (int dir = 0; dir < 6; dir++) {
				int nz = z + dz[dir], nx = x + dx[dir], ny = y + dy[dir];

				if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M
					|| tomato[nz][ny][nx]) continue;

				--noRipeCnt;
				tomato[nz][ny][nx] = 1;
				q.push({ nz,ny,nx });
			}
		}
		++day;
	}

	cout << (noRipeCnt ? -1 : day);
}