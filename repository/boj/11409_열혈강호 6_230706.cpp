#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int _MAX = 802, S = 0, T = 1, manStart = 2, jobStart = 402, INF = 1e9;

int n, m;

int cap[_MAX][_MAX];
int flow[_MAX][_MAX];
int cost[_MAX][_MAX];

vector<int> con[_MAX];

void addEdge(int from, int to, int capacity) {
	cap[from][to] = capacity;
	con[from].push_back(to);
	con[to].push_back(from);
}

bool inQ[_MAX];
int parent[_MAX];
long long dist[_MAX];
void mcmf(int& cnt, int& totalCost) {
	while (true)
	{
		memset(inQ, 0, sizeof inQ);
		memset(parent, -1, sizeof parent);
		fill(dist, dist + _MAX, INF);

		queue<int> q;
		dist[S] = 0;
		q.push(S);
		parent[S] = S;

		while (q.size())
		{
			int t = q.front(); q.pop();

			inQ[t] = false;

			for (int& next : con[t]) {
				if (cap[t][next] - flow[t][next] > 0
					&& dist[next] > dist[t] + cost[t][next]) {

					parent[next] = t;
					dist[next] = dist[t] + cost[t][next];
					
					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (parent[T] == -1) return;

		totalCost += -dist[T];
		cnt++;

		for (int p = T; p != S; p = parent[p]) {
			flow[parent[p]][p]++;
			flow[p][parent[p]]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) addEdge(i + jobStart, T, 1);

	for (int i = 0; i < n; i++) {

		int manNum = i + manStart;

		addEdge(S, manNum, 1);

		int len; cin >> len;
		while (len--)
		{
			int job, c; cin >> job >> c;
			job = job + jobStart - 1;
			cost[manNum][job] = -c;
			cost[job][manNum] = c;

			addEdge(manNum, job, 1);
		}
	}
	int cnt = 0, cost = 0;
	mcmf(cnt, cost);
	cout << cnt << "\n" << cost;
}