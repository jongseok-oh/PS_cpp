#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
int n, m,k,s,d;

int dist[1001][1000];

int minDistRoadCache[1001];

vector<pii> road[1001];

struct info {
	int node, dist, roadCnt;

	bool operator < (const info& a) const{
		if (dist == a.dist)
			return roadCnt > a.roadCnt;
		return dist > a.dist;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m>>k>>s>>d;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}

	memset(minDistRoadCache, -1, sizeof(minDistRoadCache));

	priority_queue<info> q;

	q.push({ s,0,0 });

	for (int i = 1; i <= n; i++) for (int j = 0; j < n; j++)
		dist[i][j] = 0x7fffffff;

	while (q.size()) {
		info t = q.top(); q.pop();
		int tnode = t.node,
			tdist = t.dist,
			tcnt = t.roadCnt;

		if (minDistRoadCache[tnode] == -1) {
			minDistRoadCache[tnode] = tcnt;
		}
		else if (minDistRoadCache[tnode] <= tcnt) continue;

		if (dist[tnode][tcnt] < tdist) continue;

		for (int i = 0, len = road[tnode].size(); i < len; i++) {
			int nnode = road[tnode][i].first,
				rcost = road[tnode][i].second;
			
			if (dist[nnode][tcnt + 1] > tdist + rcost) {
				dist[nnode][tcnt + 1] = tdist + rcost;
				q.push({ nnode, tdist + rcost, tcnt + 1 });
			}
		}
	}
	
	cout << dist[d][minDistRoadCache[d]] << "\n";

	while (k--) {
		int p; cin >> p;
		
		int len = minDistRoadCache[d];
		int minRoadCnt = len;
		int min_dist = 0x7fffffff;
		for (int i = 1; i <= len; i++) {
			if (dist[d][i] == 0x7fffffff) continue;
			dist[d][i] += i * p;
			if (dist[d][i] < min_dist) {
				min_dist = dist[d][i];
				minRoadCnt = i;
			}
		}
		minDistRoadCache[d] = minRoadCnt;
		cout << min_dist << "\n";
	}
}