#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int s = 0, t = 301;

int n, m;
struct Edge { int to, cap, rev; };
vector<Edge> con[302];

void addEdge(int from, int to, int cap) {
	con[from].push_back({ to, cap, (int)con[to].size()});
	con[to].push_back({ from, cap, (int)con[from].size()-1});
}

int level[302];
bool bfs() {
	memset(level, -1, sizeof level);
	queue<int> q; q.push(s);
	level[s] = 0;

	while (q.size()) {
		int node = q.front(); q.pop();

		for (auto& [to,cap,_] : con[node]) {
			if (cap > 0 && level[to] == -1) {
				level[to] = level[node] + 1;
				q.push(to);
			}
		}
	}
	return level[t] != -1;
}

int iter[302];
int dfs(int v, int f) {
	if (v == t) return f;
	for (int& i = iter[v]; i < con[v].size(); ++i) {
		auto& [to, cap, rev] = con[v][i];
		if (cap > 0 && level[v] < level[to]) {
			int d = dfs(to, min(f, cap));
			if (d > 0) {
				cap -= d;
				con[to][rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int dinic() {
	int ret = 0;
	while (bfs()) {
		memset(iter, 0, sizeof iter);
		while (int f = dfs(s, 1e9)) ret += f;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	addEdge(s, 1, 1e9); addEdge(n, t, 1e9);

	int a, b, c;
	while (m--) {
		cin>>a >> b >> c;
		addEdge(a, b, c);
	}
	cout << dinic();
}
