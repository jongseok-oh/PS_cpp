#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

#define y first
#define x second
typedef pair<int, int> Loc;

const int MAX_COST = 4 * 1e6 + 7, INF = 1e9;
int n, m;
char map[50][50];
int cost[26];

Loc s = {100, 0}, t;

struct Edge {
	Loc to;
	int cap, rev;
};
vector<Edge> con[101][50];

void addEdge(Loc from, Loc to, int cap) {
	con[from.y][from.x].push_back({ to, cap, (int)con[to.y][to.x].size() });
	con[to.y][to.x].push_back({ from, 0, (int)con[from.y][from.x].size()-1});
}

void makeCon() {
	const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if (map[i][j] == '-' || map[i][j] == '*') continue;

		// in out
		addEdge({ i, j}, { i+n, j }, cost[map[i][j]-'A'] + MAX_COST);

		// 간선
		for (int dir = 0; dir < 4; ++dir) {
			int ny = i + dy[dir], nx = j + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '-') continue;
			addEdge({ i+n, j }, { ny, nx }, INF);
		}
		
		// 가장자리
		if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
			addEdge(s, { i,j }, INF);
		}
	}
}

int level[101][50];
bool bfs() {
	memset(level, -1, sizeof level);
	level[s.y][s.x] = 0;
	queue<Loc> q; q.push(s);

	while (q.size()) {
		if (q.front() == t) return true;
		auto[ty, tx] = q.front(); q.pop();
		for (const Edge& edge : con[ty][tx]) {
			auto[ny, nx] = edge.to;
			if (edge.cap > 0 && level[ny][nx] == -1) {
				level[ny][nx] = level[ty][tx] + 1;
				q.push({ ny,nx });
			}
		}
	}
	return false;
}

int iter[101][50];
int dfs(Loc v, int f) {
	if (v == t) return f;

	for (int& i = iter[v.y][v.x]; i < con[v.y][v.x].size(); ++i) {
		Edge& edge = con[v.y][v.x][i];
		Loc to = edge.to;
		if (edge.cap > 0 && level[v.y][v.x] < level[to.y][to.x]) {
			int d = dfs(edge.to, min(f, edge.cap));
			if (d > 0) {
				edge.cap -= d;
				con[to.y][to.x][edge.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int dinic() {
	int ret = 0, f;
	while (bfs()) {
		memset(iter, 0, sizeof iter);
		while ((f = dfs(s, 1e9))){
			ret = (ret + f) % MAX_COST;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> map[i][j];
		if (map[i][j] == '*') t = { i,j };
	}
	for (int i = 0; i < 26; ++i) cin >> cost[i];
	makeCon();
	cout << dinic();
}