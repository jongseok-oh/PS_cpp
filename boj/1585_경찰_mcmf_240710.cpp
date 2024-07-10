#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int S = 100, T= 101, diff = 50, INF = 0x3f3f3f3f;

int n, t, f;
int inTime[50], outTime[50];

struct Edge {
    int to, cap, cost, rev;
};
vector<Edge> minCon[102];
vector<Edge> maxCon[102];

void addEdge(int from, int to, int cap, int cost, vector<Edge>* con) {
    con[from].push_back({ to, cap, cost, (int)con[to].size() });
    con[to].push_back({ from, 0, -cost, (int)con[from].size()-1});
}

int dist[102], prevv[102], preve[102];
bool inQ[102];
bool spfa(vector<Edge>* con) {
    memset(inQ, 0, sizeof inQ);
    memset(dist, 0x3f, sizeof dist);
    
    queue<int> q; q.push(S);
    inQ[S] = true;
    dist[S] = 0;

    while (q.size()) {
        int node = q.front(); q.pop();
        inQ[node] = false;

        for (int i = 0; i < con[node].size(); ++i) {
            auto& [to, cap, cost, rev] = con[node][i];
            if (cap > 0 && dist[to] > dist[node] + cost) {
                dist[to] = dist[node] + cost;
                prevv[to] = node; preve[to] = i;
                if (!inQ[to]) {
                    inQ[to] = true;
                    q.push(to);
                }
            }
        }
    }
    return dist[T] != INF;
}

pair<int, int> mcmf(vector<Edge>* con) {
    int flow = 0, cost = 0;
    
    while (spfa(con))
    {
        for (int v = T; v != S; v = prevv[v]) {
            Edge& edge = con[prevv[v]][preve[v]];
            --edge.cap;
            ++con[v][edge.rev].cap;
        }
        cost += dist[T];
        flow++;
    }
    return { flow, cost };
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> inTime[i];
    for (int i = 0; i < n; ++i) cin >> outTime[i];

    cin >> t>>f;
    for (int i = 0; i < n; ++i) {
        addEdge(S, i, 1, 0, minCon);
        addEdge(S, i, 1, 0, maxCon);
        addEdge(i + diff, T, 1, 0, minCon);
        addEdge(i + diff, T, 1, 0, maxCon);
        for (int j = 0; j < n; ++j) {
            if (inTime[i] < outTime[j]) {
                int s = outTime[j] - inTime[i];
                int pay = t > s ? t - s : 0;
                pay = min(pay * pay, f);
                addEdge(i, j + diff, 1, pay, minCon);
                addEdge(i, j + diff, 1, -pay, maxCon);
            }
        }
    }
    auto [flow, cost] = mcmf(minCon);
    if (flow != n) {cout << -1; return 0;}
    cout << cost << " " << -mcmf(maxCon).second;
}
