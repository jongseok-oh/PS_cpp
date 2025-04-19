#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int s = 0, t = 1, storeStart = 2, manStart = 102, INF = 1e9;

int n, m;

int cap[202][202];
int flow[202][202];
int cost[202][202];

vector<int> edges[202];

bool inQ[202];
int dist[202];
int parent[202];
int mcmf() {

	int ret = 0;

	while (true) {

		for (int i = 0; i < 202; i++) dist[i] = INF;
		memset(inQ, 0, sizeof inQ);
		memset(parent, -1, sizeof parent);

		dist[s] = 0;
		queue<int> q;
		q.push(s);

		while (q.size())
		{
			int tt = q.front(); q.pop();
			inQ[tt] = false;

			for (int next : edges[tt]) {
				if (cap[tt][next] - flow[tt][next] > 0 && dist[next] > dist[tt] + cost[tt][next]) {
					dist[next] = dist[tt] + cost[tt][next];
					parent[next] = tt;

					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (parent[t] == -1) break;

		int tflow = INF;
		for (int p = t; p != s; p = parent[p])
			tflow = min(tflow, cap[parent[p]][p] - flow[parent[p]][p]);

		for (int p = t; p != s; p = parent[p]) {
			int pp = parent[p];
			ret += tflow * cost[pp][p];
			flow[pp][p] += tflow;
			flow[p][pp] -= tflow;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int store = j + storeStart, man = i + manStart;

		cap[store][man] = INF;

		edges[store].push_back(man);
		edges[man].push_back(store);
	}

	for (int i = 0; i < n; i++) {
		int needBook; cin >> needBook;

		int man = i + manStart;

		cap[man][t] = needBook;

		edges[man].push_back(t);
		edges[t].push_back(man);
	}

	for (int i = 0; i < m; i++) {
		int bookCnt; cin >> bookCnt;

		int store = i + storeStart;

		cap[s][store] = bookCnt;

		edges[s].push_back(store);
		edges[store].push_back(s);
	}

	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
		int tcost; cin >> tcost;

		int store = i + storeStart, man = j + manStart;

		cost[store][man] = tcost;
		cost[man][store] = -tcost;
	}

	cout << mcmf();
}