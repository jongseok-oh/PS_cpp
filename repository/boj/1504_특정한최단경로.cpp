#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info {
	int cost, node, bit;

	bool operator < (const info& a) const {
		return cost > a.cost;
	}
};

typedef pair<int, int> pii;

int n, e, v1,v2;

vector<pii> edge[801];

int dist[4][801];


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	
	
	priority_queue<info> q;
	for (int j = 0; j <= 3; j++) for (int i = 1; i <= n; i++) dist[j][i] = 1e9;

	int tbit = 0;

	if (v1 == 1) tbit |= 1;

	dist[tbit][1] = 0;

	q.push({ 0,1,tbit});
	while (q.size()) {
		info t = q.top(); q.pop();
		int tcost = t.cost,
			tnode = t.node,
			tbit = t.bit;
		
		if (tbit == 3 && tnode == n) {
			cout << tcost; return 0;
		}

		if (dist[tbit][tnode] < tcost) continue;

		for (int i = 0; i < edge[tnode].size(); i++) {
			pii tt = edge[tnode][i];
			int nnode = tt.first,
				cost = tt.second;

			int ttbit = tbit;
			if (nnode == v1) ttbit |= 1;
			if (nnode == v2) ttbit |= 2;

			if (dist[ttbit][nnode] > cost + tcost) {
				dist[ttbit][nnode] = cost + tcost;
				q.push({ dist[ttbit][nnode],nnode, ttbit });
			}
		}
	}

	cout << -1;

}