#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, p;

struct Edge {int to, cap, cost, rev;};
vector<Edge> con[52];
const int s = 50, t = 51;

int person[50][50], cost[50][50];
void addEdge(int from, int to, int cap, int cost) {
    con[from].push_back({ to, cap, cost, (int)con[to].size()});
    con[to].push_back({ from, 0, -cost, (int)con[from].size() -1});
}

void makeGraph() {
    addEdge(s, 0, p, 0); addEdge(n - 1, t, p, 0);
    for (int i = 0; i < n - 1; ++i) for (int j = i+1; j < n; ++j)
        cin >> person[i][j];
    for (int i = 0; i < n - 1; ++i)for (int j = i+1; j < n; ++j)
        cin >> cost[i][j];
    for (int i = 0; i < n - 1; ++i) {
        addEdge(i, i + 1, 1e9, 0);
        for (int j = i+1; j < n; ++j) {
            addEdge(i, j, person[i][j], -cost[i][j]);
        }
    }
}

const int INF = 0x3f3f3f3f;
bool inQ[52];
int dist[52], prevv[52], preve[52];
int spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(inQ, 0, sizeof inQ);

    queue<int> q; q.push(s);
    inQ[s] = true; dist[s] = 0;
    while (q.size()) {
        int node = q.front(); q.pop();
        inQ[node] = false;
        for (int i = 0; i < con[node].size(); ++i) {
            Edge& edge = con[node][i];
            if (edge.cap > 0 && dist[edge.to] > dist[node] + edge.cost) {
                dist[edge.to] = dist[node] + edge.cost;
                prevv[edge.to] = node;
                preve[edge.to] = i;

                if (!inQ[edge.to]) {
                    inQ[edge.to] = true;
                    q.push(edge.to);
                }
            }
        }
    }
    return dist[t];
}

int mcmf() {
    int ret = 0, f;
    while ((f = spfa()) != INF) {
        int d = 1e9;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, con[prevv[v]][preve[v]].cap);
        }
        for (int v = t; v != s; v = prevv[v]) {
            Edge& edge = con[prevv[v]][preve[v]];
            edge.cap -= d;
            con[v][edge.rev].cap += d;
        }
        ret += f * d;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    makeGraph();
    cout << -mcmf();
}