#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct info {
	int node, cost;
	bool operator < (info b) const {
		return this->cost > b.cost;
	}
};

vector<info> edges[1001];

int dist[1001];
int parent[1001];

int dijkstra(int from, int to) {
	for (int i = 1; i <= n; i++) dist[i] = 1e9;

	dist[1] = 0;
	priority_queue<info> q;
	q.push({ 1,0 });

	while (q.size()) {
		info t = q.top(); q.pop();

		int tnode = t.node,
			tcost = t.cost;

		if (tnode == n) return tcost;
		if (dist[tnode] > tcost) continue;

		for (const auto& next : edges[tnode]) {
			int nnode = next.node,
				ncost = next.cost;

			if (tnode == from && nnode == to) continue;

			if (dist[nnode] > ncost + tcost) {
				dist[nnode] = ncost + tcost;
				q.push({ nnode, dist[nnode] });
				if(to == -1) parent[nnode] = tnode;
			}
		}
	}
	return 1e9;
}

void trace(vector<int>& vec, int node) {
	vec.push_back(node);
	if (node == 1) return;
	trace(vec,parent[node]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	int shortLen = dijkstra(-1, -1);
	int ans = -1;

	vector<int> vec;
	trace(vec, n);

	// 최단경로를 이루는 도로들만 막아보면 된다
	// 다른 최단경로가 존재하는 경우 -> 어떤 도로를 막아도 다른 최단경로로 귀결됨
	// 다른 최단경로가 존재하지 않는 경우 -> 최단경로 상의 도로를 하나씩 막아보며
	// 최대 경로를 찾아감

	for (int i = vec.size() - 1; i > 0; i--) {
		int tLen = dijkstra(vec[i], vec[i - 1]);
		if (tLen == 1e9) {
			cout << -1; return 0;
		}
		ans = ans < tLen - shortLen ? tLen - shortLen : ans;
	}
	cout << ans;
}