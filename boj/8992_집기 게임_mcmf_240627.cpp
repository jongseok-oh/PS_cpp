#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

struct Line { int x1, y1, x2, y2, w;};
Line lines[400];

int s = 400, t = 401;
struct Edge { int to, cap, cost, rev; };
vector<Edge> con[402];

void addEdge(int from, int to, int cap, int cost) {
	con[from].push_back({ to, cap, cost, (int)con[to].size() });
	con[to].push_back({ from, 0, -cost, (int)con[from].size()-1});
}

const int INF = 0x3f3f3f3f;
bool inQ[402];
int dist[402], prevv[402], preve[402];
bool spfa() {
	memset(inQ, 0, sizeof inQ);
	memset(dist, 0x3f, sizeof dist);

	queue<int> q; q.push(s);
	dist[s] = 0; inQ[s] = true;

	while (q.size())
	{
		int node = q.front(); q.pop();
		inQ[node] = false;

		for (int i = 0; i < con[node].size(); ++i) {
			auto& [to, cap, cost, _] = con[node][i];
			if (cap > 0 && dist[to] > dist[node] + cost) {
				dist[to] = dist[node] + cost;
				prevv[to] = node;
				preve[to] = i;
				if (!inQ[to]) {
					inQ[to] = true; q.push(to);
				}
			}
		}
	}
	return dist[t] != INF;
}

pair<int, int> mcmf() {
	int flow = 0, cost = 0;
	while (spfa())
	{
		for (int v = t; v != s; v = prevv[v]) {
			Edge& edge = con[prevv[v]][preve[v]];
			--edge.cap;
			++con[v][edge.rev].cap;
		}
		flow++;
		cost += dist[t];
	}
	return { flow, cost };
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		con[s].clear(); con[t].clear();
		for (int i = 0; i < n; ++i) {
			auto& line = lines[i];
			cin >> line.x1 >> line.y1 >> line.x2 >> line.y2 >> line.w;
			if (line.x1 > line.x2) swap(line.x1, line.x2);
			con[i].clear();

			addEdge(s, i, 1, 0);
		}
			
		for (int i = n; i < n + m; ++i) {
			auto& line = lines[i];
			cin >> line.x1 >> line.y1 >> line.x2 >> line.y2 >> line.w;
			if (line.y1 > line.y2) swap(line.y1, line.y2);
			con[i].clear();

			addEdge(i, t, 1, 0);
		}
			
		for (int i = 0; i < n; ++i) for (int j = n; j < n + m; ++j) {
			Line a = lines[i], b = lines[j];
			if (a.x1 < b.x1 && b.x1 < a.x2 && b.y1 < a.y1 && a.y1 < b.y2) {
				addEdge(i, j, 1,- a.w * b.w);
			}
		}
		auto [flow, cost] = mcmf();
		cout << flow << " " << -cost << "\n";
	}
}
