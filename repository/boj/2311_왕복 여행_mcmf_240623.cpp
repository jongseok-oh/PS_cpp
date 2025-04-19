#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
struct Edge { int to, cap, cost, rev; };
vector<Edge> con[1001];

void addEdge(int from, int to, int cap, int cost) {
	con[from].push_back({ to, cap, cost, (int)con[to].size() });
	con[to].push_back({ from, 0, -cost, (int)con[from].size()-1});
}

int s = 1, t;
const int INF = 0x3f3f3f3f;
int dist[1001], prevv[1001], preve[1001];
bool inQ[1001];
int mcmf() {
	memset(dist, 0x3f, sizeof dist);
	memset(inQ, 0, sizeof inQ);

	queue<int> q; q.push(s);
	inQ[s] = true; dist[s] = 0;

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

	int d = 1e9;
	for (int v = t; v != s; v = prevv[v]) {
		d = min(d, con[prevv[v]][preve[v]].cap);
	}

	for (int v = t; v != s; v = prevv[v]) {
		Edge& edge = con[prevv[v]][preve[v]];
		edge.cap -= d;
		con[v][edge.rev].cap += d;
	}
	
	return dist[t] * d;
}

int main() {
	cin >> n >> m;
	t = n;

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b>>c;
		addEdge(a, b, 1, c);
		addEdge(b, a, 1, c);
	}

	cout << mcmf() + mcmf();
}