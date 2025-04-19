#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

bool map[10][10];
bool visit[10][10] = {false,};

struct loc {int y, x;};
struct edge { int i, j, w;};

int dy[] = { 1,0,-1,0 }, dx[] = { 0,1,0,-1 };

bool cmp(edge a, edge b) { return a.w < b.w;}

int parent[6];

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

bool Union(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);

	if (rootA == rootB) return false;
	
	parent[rootB] = rootA;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];

	vector < vector <loc >> islands;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (!visit[i][j] && map[i][j]) {
			queue<loc> q;
			vector <loc > island;
			q.push({ i,j }); island.push_back({ i,j });
			visit[i][j] = true;
			while (q.size()) {
				loc t = q.front(); q.pop();
				int y = t.y, x = t.x;

				for (int dir = 0; dir < 4; dir++) {
					int ny = y + dy[dir], nx = x + dx[dir];
					if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
					if (visit[ny][nx]) continue;
					if (!map[ny][nx]) continue;
					visit[ny][nx] = true;
					q.push({ ny,nx }); island.push_back({ ny,nx });
				}
			}
			islands.push_back(island);
		}
	}

	// find edges
	int landCnt = islands.size();

	vector<edge> edges;

	bool chk[6][6] = {false,};

	for (int i = 0; i < landCnt; i++) {
		for (int j = 0; j < landCnt; j++) {
			if (i == j)continue;
			if (chk[j][i]) continue;
			vector<loc> islandA = islands[i];
			vector<loc> islandB = islands[j];

			int minDist = 1e9;
			for (int a = 0, alen = islandA.size(); a < alen; a++) {
				for (int b = 0, blen = islandB.size(); b < blen; b++) {
					bool flag = true;
					if (islandA[a].y == islandB[b].y) {
						int y = islandA[a].y;
						int sx = islandA[a].x > islandB[b].x ? islandB[b].x : islandA[a].x;
						int lx = islandA[a].x > islandB[b].x ? islandA[a].x : islandB[b].x;
						while (sx != lx - 1) {
							++sx;
							if (map[y][sx]) { flag = false;break;}
						}
						if (flag) {
							int tdist = abs(islandA[a].x - islandB[b].x) - 1;
							if(tdist >=2) minDist = tdist > minDist ? minDist : tdist;
						}
					}
					else if (islandA[a].x == islandB[b].x) {
						int x = islandA[a].x;
						int sy = islandA[a].y > islandB[b].y ? islandB[b].y : islandA[a].y;
						int ly = islandA[a].y > islandB[b].y ? islandA[a].y : islandB[b].y;
						while (sy != ly-1) {
							++sy;
							if (map[sy][x]) { flag = false; break; }
						}
						if (flag) {
							int tdist = abs(islandA[a].y - islandB[b].y) - 1;
							if(tdist >= 2) minDist = tdist > minDist ? minDist : tdist;
						}
					}
				}
			}
			if (minDist != 1e9) {
				edges.push_back({ i, j, minDist });
				chk[i][j] = true;
			}
		}
	}
	sort(edges.begin(), edges.end(), cmp);

	// 크루스칼
	for (int i = 0; i < 6; i++) parent[i] = i;

	int ans = 0, cnt = 0;
	for (int i = 0, len = edges.size(); i < len; i++) {
		edge t = edges[i];
		if (Union(t.i, t.j)) { cnt++; ans += t.w;}
		if (cnt == landCnt - 1) break;
	}
	cout << (cnt == landCnt - 1 ? ans : -1);
}