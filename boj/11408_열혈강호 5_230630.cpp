#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int s = 0, d = 801;

int n, m;

bool con[802][802];
int flow[802][802];

struct edge {int t, cost;};
vector<edge> edges[802];

int cnt = 0, minCost = 0;
int parent[802];
bool inQ[802];
long long dist[802];
void mcmf() {
	while (true)
	{
		memset(parent, -1, sizeof parent);
		memset(inQ, 0, sizeof inQ);

		for (int i = 0; i < 802; i++) dist[i] = 0x7fffffff;

		queue<int> q;
		q.push(s);
		dist[s] = 0;
		parent[s] = s;

		while (q.size())
		{
			int tt = q.front(); q.pop();
			inQ[tt] = false;
			
			for (auto& e : edges[tt]) {
				int next = e.t;
				int cost = e.cost;

				if (dist[tt] + cost < dist[next]
					&& con[tt][next] - flow[tt][next] > 0) {
					dist[next] = dist[tt] + cost;
					parent[next] = tt;
					
					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (parent[d] == -1) break;
		cnt++; minCost += dist[d];

		for (int p = d; p != s; p = parent[p]) {
			flow[parent[p]][p]++;
			flow[p][parent[p]]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {

		edges[s].push_back({ i,0 });
		edges[i].push_back({ s,0 });
		con[s][i] = 1;

		int len; cin >> len;
		while (len--) {
			int work, cost; cin >> work >> cost;
			work += 400;

			edges[i].push_back({ work, cost });
			edges[work].push_back({ i, -cost });
			con[i][work] = 1;

			edges[work].push_back({ d,0 });
			edges[d].push_back({ work,0 });
			con[work][d] = 1;
		}
	}
	mcmf();
	cout << cnt << "\n" << minCost;
}