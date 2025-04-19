#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;

struct info {
	int node, dist;
	const bool operator <(const info& b) const {
		return dist > b.dist;
	}
};

vector<info> edges[20000];

int dist[20000];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> v >> e;

	int start; cin >> start; start--;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[--a].push_back({ --b,c });
	}

	for (int i = 0; i < v; i++) dist[i] = 1e9;
	priority_queue<info> q;
	q.push({ start,0 }); dist[start] = 0;
	
	while (q.size()) {
		info t = q.top(); q.pop();
		int tNode = t.node, tDist = t.dist;
		if (t.dist > dist[tNode]) continue;

		for (int i = 0; i < edges[tNode].size(); i++) {
			int nNode = edges[tNode][i].node, nDist = edges[tNode][i].dist;
			if (dist[nNode] > tDist + nDist) {
				dist[nNode] = tDist + nDist;
				q.push({ nNode, dist[nNode]});
			}
		}
	}
	for (int i = 0; i < v; i++) {
		if (dist[i] == 1e9) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
}