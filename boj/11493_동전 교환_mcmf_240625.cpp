#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int s = 501, t = 502;
const int INF = 0x3f3f3f3f;

struct Edge { int to, cap, cost, rev;};
vector<Edge> con[503];

void addEdge(int from, int to, int cap, int cost) {
	con[from].push_back({ to, cap, cost, (int)con[to].size() });
	con[to].push_back({ from, 0, -cost, (int)con[from].size()-1});
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) con[i].clear();
	con[s].clear(); con[t].clear();

	int a, b;
	while (m--) {
		cin >> a >> b;
		addEdge(a, b, INF, 1);
		addEdge(b, a, INF, 1);
	}

	int color;
	for (int i = 1; i <= n; ++i) {
		cin >> color;
		if (color) addEdge(s, i, 1, 0);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> color;
		if (color) addEdge(i, t, 1, 0);
	}
}

bool inQ[503];
int dist[503], prevv[503], preve[503];
bool spfa() {
	memset(dist, 0x3f, sizeof dist);
	memset(inQ, 0, sizeof inQ);

	queue<int> q; q.push(s);
	dist[s] = 0; inQ[s] = true;

	while (q.size()) {
		int node = q.front(); q.pop();
		inQ[node] = false;

		for (int i = 0; i < con[node].size(); ++i) {
			Edge& edge = con[node][i];

			if (edge.cap > 0 && dist[edge.to] > dist[node] + edge.cost) {

				dist[edge.to] = dist[node] + edge.cost;
				prevv[edge.to] = node;
				preve[edge.to] = i;

				if (!inQ[edge.to]) {
					inQ[edge.to] = true;
					q.push(edge.to);
				}
			}
		}
	}
	return dist[t] != INF;
}

int mcmf() {
	int ret = 0;
	while (spfa()) {
		for (int v = t; v != s; v = prevv[v]) {
			Edge& edge = con[prevv[v]][preve[v]];
			edge.cap--;
			con[v][edge.rev].cap++;
		}
		ret += dist[t];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		init();
		cout << mcmf() << "\n";
	}
}
