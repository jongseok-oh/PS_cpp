#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, x;

vector<pii> road[1001];

int dist[1001][1001];

void dijkstra(int start) {
	dist[start][start] = 0;
	priority_queue<pii> q;
	q.push({ 0,start });

	while (q.size()) {
		pii t = q.top(); q.pop();

		int cost = -t.first;
		int node = t.second;
		if (dist[start][node] < cost) continue;

		for (pii& nroad : road[node]) {
			int nnode = nroad.first;
			int tcost = nroad.second;

			if (dist[start][nnode] > cost + tcost) {
				dist[start][nnode] = cost + tcost;
				q.push({ -dist[start][nnode], nnode });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;

	int a, b, c;
	while (m--)
	{
		cin >> a >> b >>c;
		road[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = 0x7fffffff;

	for (int i = 1; i <= n; i++) dijkstra(i);

	int _max = -1;
	for (int i = 1; i <= n; i++)
		_max = max(_max, dist[i][x] + dist[x][i]);
	cout << _max;
}