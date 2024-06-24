#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int n, m;
int s = 213, t = 214;

struct Edge { int to, cap, rev;};
vector<Edge> con[215];

void addEdge(int from, int to, int cap) {
	con[from].push_back({ to, cap, (int)con[to].size() });
	con[to].push_back({ from, 0, (int)con[from].size()-1});
}

int level[215];
bool bfs() {
	memset(level, -1, sizeof level);
	queue<int> q; q.push(s);
	level[s] = 0;
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

int iter[215];
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
	int ret = 0;
	while (bfs()) {
		memset(iter, 0, sizeof iter);
		int f;
		while ((f = dfs(s, 1e9))) ret += f;
	}
	return ret;
}

int main() {
	cin >> n>>m;
	int needBook;
	for (int i = 0; i < n; ++i) {
		cin >> needBook;
		if (!needBook) continue;
		addEdge(s, i, needBook);
	}
	
	int book;
	for (int i = 100; i < m + 100; ++i) {
		cin >> book;
		if (!book) continue;
		addEdge(i, t, book);
	}

	int maxBook;
	for (int j = 100; j < 100 + m; ++j) for (int i = 0; i < n; ++i)  {
		cin >> maxBook;
		if (!maxBook) continue;
		addEdge(i, j, maxBook);
	}
	cout << dinic();
}