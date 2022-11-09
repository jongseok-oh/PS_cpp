#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;

int cost[2501];

struct info
{
	int min_cost,node;
	ll dist;
	bool operator < (const info& a) const{
		return dist > a.dist;
	}
};

vector<pii> road[2501];

ll dist[2501][2501];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	int max_cost = -1;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		max_cost = max(max_cost, cost[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}

	priority_queue<info> q;
	q.push({ cost[1], 1, 0 });

	for (int i = 1; i <= n; i++) for (int j = 1; j <= max_cost; j++)
		dist[i][j] = 0x7fffffffffffffff;

	dist[1][cost[1]] = 0;

	// int min_cost,node; ll dist;
	while (true) {
		info t = q.top(); q.pop();

		int node = t.node;
		ll tDist = t.dist;
		if (node == n) {
			cout << tDist; return 0;
		}
		int min_cost = min(t.min_cost, cost[node]);
		if (dist[node][min_cost] < tDist) continue;
		for (int i = 0, len = road[node].size(); i < len; i++) {
			int nNode = road[node][i].first,
				roadLen = road[node][i].second;

			ll nnDist = tDist + min_cost * roadLen;

			if (dist[nNode][min_cost] > nnDist) {
				dist[nNode][min_cost] = nnDist;
				q.push({ min_cost,nNode,nnDist });
			}
		}
	}
}