#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int n,m, s = 1,t;

struct Edge {
	int to, cap, rev;
};
vector<Edge> con[301];

struct EdgeInfo { int from, idx;};
vector<EdgeInfo> edgeInfoes;

void addEdge(int from, int to, int cap) {
	edgeInfoes.push_back({ from, (int)con[from].size() });

	con[from].push_back({ to, cap, (int)con[to].size()});
	con[to].push_back({ from, 0, (int)con[from].size()-1});
}

void init() {
	cin >> n >> m;
	t = n;
	edgeInfoes.clear();
	for (int i = 1; i <= n; ++i) {
		con[i].clear();
	}
}

int level[301];
bool bfs() {
	memset(level, -1, sizeof level);
	level[s] = 0;
	queue<int> q; q.push(s);
	
	while (q.size()) {
		int node = q.front(); q.pop();
		if (node == t) return true;
		for (Edge& edge : con[node]) {
			int to = edge.to;
			if (edge.cap > 0 && level[to] == -1) {
				level[to] = level[node] + 1;
				q.push(to);
			}
		}
	}
	return false;
}

int iter[301];
int dfs(int v, int f) {
	if (v == t) return f;
	for (int& i = iter[v]; i < con[v].size(); ++i) {
		Edge& edge = con[v][i];
		if (edge.cap > 0 && level[v] < level[edge.to]) {
			int d = dfs(edge.to, min(f, edge.cap));
			if (d > 0) {
				edge.cap -= d;
				con[edge.to][edge.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

void dinic() {
	while (bfs()) {
		memset(iter, 0, sizeof iter);
		while (dfs(s, 1e9));
	}
}

bool visit[301];
bool canGo(int v, int to) {
	memset(visit, 0, sizeof visit);

	queue<int> q; q.push(v);
	visit[v] = true;

	while (q.size()) {
		int node = q.front(); q.pop();
		
		if (node == to) return true;

		for (Edge edge : con[node]) {
			if (!visit[edge.to] && edge.cap > 0) {
				visit[edge.to] = true;
				q.push(edge.to);
			}
		}
	}
	return false;
}

int solve() {
	dinic();
	int ret = 0;
	for (auto&[v, idx] : edgeInfoes) {
		Edge& edge = con[v][idx];
		if (edge.cap == 0 && !canGo(v, edge.to))
			++ret;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int k; cin >> k;
	while (k--) {
		init();
		
		int a, b, c;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> c;
			addEdge(a, b, c);
		}
		cout << solve() << "\n";
	}
};