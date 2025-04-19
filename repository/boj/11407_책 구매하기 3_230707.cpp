#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int S = 0, D = 1, manStart = 2, storeStart = 102, _MAX = 202, INF = 1e9;

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
int dist[_MAX];

void mcmf(int& cnt, int& minCost) {
	while (true)
	{
		memset(inQ, 0, sizeof inQ);
		memset(parent, -1, sizeof parent);
		fill(dist, dist + _MAX, INF);

		queue<int> q;

		dist[S] = 0;
		parent[S] = S;
		q.push(S);

		while (q.size())
		{
			int t = q.front(); q.pop();
			inQ[t] = false;

			for (int& next : con[t]) {
				if (dist[next] > dist[t] + cost[t][next]
					&& cap[t][next] > flow[t][next]) {

					dist[next] = dist[t] + cost[t][next];
					parent[next] = t;

					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (parent[D] == -1) return;


		int tFlow = INF;

		for (int p = D; p != S; p = parent[p])
			tFlow = min(tFlow, cap[parent[p]][p] - flow[parent[p]][p]);

		cnt += tFlow;
		minCost += dist[D] * tFlow;

		for (int p = D; p != S; p = parent[p]) {
			flow[parent[p]][p] += tFlow;
			flow[p][parent[p]] -= tFlow;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int needBook; cin >> needBook;

		int manNum = i + manStart;

		addEdge(manNum, D, needBook);
	}

	for (int i = 0; i < m; i++) {
		int bookCnt; cin >> bookCnt;

		int storeNum = i + storeStart;
		addEdge(S, storeNum, bookCnt);
	}

	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
		int canBuy; cin >> canBuy;

		int storeNum = i + storeStart;
		int manNum = j + manStart;
		
		addEdge(storeNum, manNum, canBuy);
	}

	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
		int tcost; cin >> tcost;
		
		int storeNum = i + storeStart;
		int manNum = j + manStart;

		cost[storeNum][manNum] = tcost;
		cost[manNum][storeNum] = -tcost;
	}

	int cnt = 0, minCost = 0;
	mcmf(cnt, minCost);
	cout << cnt << "\n" << minCost;
}