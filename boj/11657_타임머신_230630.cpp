#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int n, m;

struct Loc {int t, cost;};
vector<Loc> edge[500];

bool inQ[500];
int updated[500];
long long dist[500];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		edge[--a].push_back({ --b, c });
	}

	for (int i = 1; i < n; i++) dist[i] = INF;
	
	queue<int> q; q.push(0);
	updated[0]++;

	while (q.size())
	{
		int t = q.front(); q.pop();
		inQ[t] = false;

		for (auto loc : edge[t]) {
			int next = loc.t;
			int cost = loc.cost;

			if (dist[next] > dist[t] + cost) {
				dist[next] = dist[t] + cost;

				if (!inQ[next]) {
					if (++updated[next] >= n) {
						cout << -1; return 0;
					}
					q.push(next);
					inQ[next] = true;
				}
			}
		}
	}

	for (int i = 1; i < n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
}