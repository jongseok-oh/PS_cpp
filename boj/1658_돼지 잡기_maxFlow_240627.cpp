#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>

using namespace std;

int m, n;

const int s = 1100, t = 1101, pigStart = 100;
struct Edge { int to, cap, rev; };
vector<Edge> con[1102];
unordered_set<int> keys[1102];

void addEdge(int from, int to, int cap) {
	con[from].push_back({ to, cap, (int)con[to].size() });
	con[to].push_back({ from, 0, (int)con[from].size() -1});
}

int level[1102];
bool bfs() {
	memset(level, -1, sizeof level);
	queue<int> q; q.push(s);
	level[s] = 0;

	while (q.size()) {
		int node = q.front(); q.pop();
		
		for (Edge& edge : con[node]) {
			if (edge.cap > 0 && level[edge.to] == -1) {
				level[edge.to] = level[node] + 1;
				q.push(edge.to);
			}
		}
	}
	return level[t] != -1;
}

int iter[1102];
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

int dinic() {
	int flow = 0;
	while (bfs()) {
		memset(iter, 0, sizeof iter);
		while (int f = dfs(s, 1e9)) flow += f;
	}
	return flow;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	int pig;
	for (int i = pigStart; i < pigStart+m; ++i) {
		cin >> pig;
		addEdge(i, t, pig);
	}
	int k, key, need;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		while (k--) {
			cin >> key;
			key += pigStart-1;
			keys[i].insert(key);
			addEdge(i, key, 1e9);
		}
		cin >> need;
		addEdge(s, i, need);
	}

	for (int i = n - 1; i > 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			for (int tKey : keys[i]) {
				if (keys[j].count(tKey)) {
					addEdge(i, j, 1e9); break;
				}
			}
		}
	}
	cout << dinic();
}
