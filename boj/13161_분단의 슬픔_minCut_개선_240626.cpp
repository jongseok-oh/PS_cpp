#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, s = 500, t = 501;
int place[500];

struct Edge { int to, cap, rev; };
vector<Edge> con[502];

void addEdge(int from, int to, int cap) {
	con[from].push_back({ to, cap, (int)con[to].size() });
	con[to].push_back({ from, 0, (int)con[from].size() - 1 });
}

int level[502];
bool bfs() {
	memset(level, -1, sizeof level);

	queue<int> q; q.push(s);
	level[s] = 0;

	while (q.size()) {
		int node = q.front(); q.pop();
		if (node == t) return true;

		for (auto& [to, cap, rev] : con[node]) {
			if (cap > 0 && level[to] == -1) {
				level[to] = level[node] + 1;
				q.push(to);
			}
		}
	}
	return false;
}

int iter[502];
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
	int flow = 0;
	while (bfs()) {
		memset(iter, 0, sizeof iter);
		while (int f = dfs(s, 1e9)) {
			flow += f;
		}
	}
	return flow;
}

bool visit[502];
void coloring() {
	visit[s] = true;
	queue<int> q; q.push(s);
	while (q.size()) {
		int node = q.front(); q.pop();
		for (Edge& edge : con[node]) {
			if (edge.cap > 0 && !visit[edge.to]) {
				visit[edge.to] = true;
				q.push(edge.to);
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (visit[i]) cout << i + 1 << " ";
	cout << "\n";
	for (int i = 0; i < n; ++i)
		if (!visit[i]) cout << i + 1 << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> place[i];
		if (place[i] == 1) addEdge(s, i, 1e9);
		else if (place[i] == 2) addEdge(i, t, 1e9);
	}

	int ret = 0, sad;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		cin >> sad;
		if (i >= j) continue;

		// 간선 몇개 생략 가능
		// 근데 별로 안빨라짐 ㅋ;
		if ((place[i] == 1 && place[j] == 2) || (place[i] == 2 && place[j] == 1)) ret += sad;
		else if(place[i] ==0 || place[j] == 0){
			addEdge(i, j, sad);
			addEdge(j, i, sad);
		}
	}
	cout << ret + dinic() << "\n";
	coloring();
}
