#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

struct info
{
	int shame, node, cost;
	bool operator < (info a) const {
		return cost > a.cost;
	}
};

int n, m, a, b, c;

vector<pii> roads[11];

int dist[11][10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b >> c;

	int t, f, co;
	for (int i = 0; i < m; i++) {
		cin >> t >> f >> co;
		roads[t].push_back({ f,co });
		roads[f].push_back({ t,co });
	}

	for (int i = 1; i <= n; i++) for (int j = 0; j <= c; j++) dist[i][j] = 1e9;

	priority_queue<info> q;
	q.push({ 0, a, 0});
	dist[a][0] = 0;
	while (q.size()) {
		info t = q.top(); q.pop();
		
		for (pii& road : roads[t.node]) {
			int nNode = road.first,
				nCost = road.second + t.cost,
				nShame = max(road.second, t.shame);
			if (nCost <= c && dist[nNode][nCost] > nShame) {
				q.push({ nShame, nNode, nCost });
				dist[nNode][nCost] = nShame;
			}
		}
	}
	
	int ans = 1e9;
	for (int i = 0; i <= c; i++) ans = min(ans, dist[b][i]);
	cout << (ans == 1e9 ? -1 : ans);
}