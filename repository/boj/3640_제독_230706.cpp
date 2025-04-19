#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int _MAX = 2000, INF = 1e9;

int v, e;
int unused = 0;

struct Edge {
	Edge* rev;
	int cap, flow, cost, next;
}edges[25000];

Edge* getEdge(int cap, int flow, int cost, int next) {
	edges[unused].cap = cap;
	edges[unused].flow = flow;
	edges[unused].cost = cost;
	edges[unused].next = next;

	return &edges[unused++];
}

vector<Edge*> con[_MAX];

void addEdge(int from, int to, int cost, int capacity) {
	Edge* in2out = getEdge(capacity, 0, cost, to);
	Edge* out2in = getEdge(0, 0, -cost, from);

	in2out->rev = out2in;
	out2in->rev = in2out;

	con[from].push_back(in2out);
	con[to].push_back(out2in);
}

bool inQ[_MAX];
int dist[_MAX];
Edge* parent[_MAX];
int mcmf() {
	int dest = (v - 1) * 2;
	int ret = 0, cnt = 0;
	while (true)
	{
		memset(inQ, 0, sizeof inQ);
		memset(parent, 0, sizeof parent);
		fill(dist, dist + _MAX, INF);

		queue<int> q;

		dist[1] = 0;
		q.push(1);

		while (q.size())
		{
			int t = q.front(); q.pop();
			inQ[t] = false;

			for (auto edge : con[t]) {
				int next = edge->next;
				if (next != 1 && edge->cap - edge->flow > 0
					&& dist[next] > dist[t] + edge->cost) {

					parent[next] = edge;
					dist[next] = dist[t] + edge->cost;

					if (!inQ[next]) {
						inQ[next] = true;
						q.push(edge->next);
					}
				}
			}
		}


		ret += dist[dest];
		if (++cnt == 2) break;

		for (auto p = parent[dest]; p != 0; p = parent[p->rev->next]) {
			p->flow++;
			p->rev->flow--;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (true) {
		cin >>v>> e;

		if (cin.eof()) break;

		unused = 0;
		for (int i = 0; i < _MAX; i++) con[i].clear();

		// 정점 분리
		for (int i = 0; i < v; i++) addEdge(i * 2, i * 2 + 1, 0, 1);

		// 간선 연결
		for (int i = 0; i < e; i++) {
			int a, b, c; cin >> a >> b >> c;
			--a; --b;

			addEdge(a * 2 + 1, b * 2, c, 1);
		}

		
		cout << mcmf() << "\n";
	}
}