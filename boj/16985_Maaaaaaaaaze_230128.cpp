#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool map[5][5][5];
bool copyBoard[5][5];

void rotate(bool board[][5]) {
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
		copyBoard[j][4 - i] = board[i][j];
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++)
		board[i][j] = copyBoard[i][j];
}

int order[5];
bool visit[5];

int ans = 1e9;

struct loc {
	int z, y, x;
};

bool sVisit[5][5][5];

int dy[] = { 0,0,1,-1,0,0 },
dx[] = { 1,-1,0,0,0,0 },
dz[] = { 0,0,0,0,1,-1 };

int simulate(const loc& start, const loc& end) {
	if (!map[order[start.z]][start.y][start.x]
		|| !map[order[end.z]][end.y][end.x]) return 1e9;
	memset(sVisit, 0, sizeof(sVisit));
	sVisit[start.z][start.y][start.x] = true;
	queue<loc> q;
	q.push(start);
	int move = 0;
	while (q.size()) {
		int qsize = q.size();
		while (qsize--) {
			loc t = q.front(); q.pop();
			if (t.z == end.z && t.y == end.y && t.x == end.x) {
				if (move == 12) {
					cout << 12;
					exit(0);
				}
				return move;
			}
			for (int dir = 0; dir < 6; dir++) {
				int nz = t.z + dz[dir],
					ny = t.y + dy[dir],
					nx = t.x + dx[dir];

				if (nz < 0 || nz > 4 || ny < 0 || ny > 4 || nx < 0 || nx > 4)
					continue;
				if (!map[order[nz]][ny][nx] || sVisit[nz][ny][nx]) continue;
				sVisit[nz][ny][nx] = true;
				q.push({ nz,ny,nx });
			}
		}
		move++;
	}
	return 1e9;
}

int enter[][2] = { {0,0},{0,4},{4,0},{4,4} };

void crazyRotate(int idx) {
	if (idx == 5) {
		for (int i = 0; i < 4; i++) {
			ans = min(simulate({ 0, enter[i][0], enter[i][1] }, { 4, 4 - enter[i][0], 4 - enter[i][1] }), ans);
		}
		return;
	}
	for (int rot = 0; rot < 4; rot++) {
		rotate(map[order[idx]]);
		crazyRotate(idx + 1);
	}
}

void buildBoard(int idx) {
	if (idx == 5) {
		crazyRotate(0);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		order[idx] = i;
		buildBoard(idx + 1);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) for (int k = 0; k < 5; k++)
		cin >> map[i][j][k];

	buildBoard(0);

	cout << (ans == 1e9 ? -1 : ans);
}