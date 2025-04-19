#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

int map[22][22];

struct info
{
	int y, x, dir;
};

vector<info> hashTable[10000];

int n;

void init(int N, int mMap[20][20])
{
	for (int i = 0; i < 10000; i++) hashTable[i].clear();

	n = N;

	memset(map, 0, sizeof(map));

	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) map[i][j] = mMap[i-1][j-1];

	for (int length = 2; length <= 5; length++) {
		for (int dir = 0; dir < 2; dir++) {
			for (int i = 0; i < N - dy[dir] * (length - 1); i++) {
				for (int j = 0; j < N - dx[dir] * (length - 1); j++) {
					
					int thash = 0;
					int y = i, x = j;

					for (int tlen = 0; tlen < length - 1; tlen++)
						thash = thash * 10 +
						(mMap[y + dy[dir] * (tlen)][x + dx[dir] * (tlen)]
							- mMap[y + dy[dir] * (tlen + 1)][x + dx[dir] * (tlen + 1)]
							+ 5);

					hashTable[thash].push_back({ y + 1,x + 1,dir });

					int tReverseHash = 0;
					int ry = i + dy[dir] * (length - 1), rx = j + dx[dir] * (length - 1);

					for (int tlen = 0; tlen < length-1; tlen++)
						tReverseHash = tReverseHash * 10
						+ (mMap[ry + dy[dir^2] * (tlen)][rx + dx[dir^2] * (tlen)]
							- mMap[ry + dy[dir ^ 2] * (tlen + 1)][rx + dx[dir ^ 2] * (tlen + 1)]
							+ 5);

					if (thash != tReverseHash) {
						hashTable[tReverseHash].push_back({ ry + 1,rx + 1,dir^2 });
					}
				}
			}
		}
	}
}

int numberOfCandidate(int M, int mStructure[5])
{
	if (M == 1) return n * n;

	int thash = 0;

	for (int i = 0; i <M - 1; i++)
		thash = thash * 10 + (mStructure[i + 1] - mStructure[i] + 5);

	return hashTable[thash].size();
}

struct loc {
	int y, x, originValue;
}q[5000];

int bfs(int mSeaLevel) {
	int front = 0, qcnt = 0;
	q[qcnt++] = { 0,0, map[0][0]};

	int ret = n * n;

	while (front < qcnt)
	{
		loc tloc = q[front++];
		int ty = tloc.y, tx = tloc.x;

		if (ty >= 1 && ty <= n && tx >= 1 && tx <= n) ret--;

		for (int dir = 0; dir < 4; dir++) {
			int ny = ty + dy[dir],
				nx = tx + dx[dir];

			if (ny <0 || ny > n + 1 || nx <0 || nx > n + 1) continue;
			if (map[ny][nx] >= mSeaLevel) continue;
			q[qcnt++] = { ny,nx,map[ny][nx]};
			map[ny][nx] = 30;
		}
	}

	// 원복
	for (int i = 0; i < qcnt; i++) map[q[i].y][q[i].x] = q[i].originValue;

	return ret;
}

int maxArea(int M, int mStructure[5], int mSeaLevel)
{
	if (M == 1) {
		int ans = 0;
		for (int i = 1; i <=n; i++) for (int j = 1; j <=n; j++) {
			map[i][j] += mStructure[0];
			ans = max(ans, bfs(mSeaLevel));
			map[i][j] -= mStructure[0];
		}
		return ans;
	}
	else {
		int thash = 0;

		for (int i = 0; i <M -1; i++)
			thash = thash * 10 + (mStructure[i +1] - mStructure[i] + 5);

		if (!hashTable[thash].size()) return -1;

		int ans = 0;

		for (int i = 0, len = hashTable[thash].size(); i < len; i++) {
			info tinfo = hashTable[thash][i];

			for (int m = 0; m < M; m++) {
				map[tinfo.y + dy[tinfo.dir] * m][tinfo.x + dx[tinfo.dir] * m]
					+= mStructure[m];
			}
			ans = max(ans, bfs(mSeaLevel));
			for (int m = 0; m < M; m++) {
				map[tinfo.y + dy[tinfo.dir] * m][tinfo.x + dx[tinfo.dir] * m]
					-= mStructure[m];
			}
		}
		return ans;
	}
}