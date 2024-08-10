#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
using pii = pair<int, int>;

struct Edge { int to, cost;};
vector<Edge> con[5001];

int dijkstra(int s, int t) {
    vector<int> dist(n + 1, 1e9);
    priority_queue<pii> q;
    dist[s] = 0;
    q.push({ 0, s });
    while (q.size()) {
        auto [tcost, node] = q.top(); q.pop();
        tcost *= -1;
        if (node == t) return tcost;
        if (dist[node] < tcost) continue;

        for (auto&[to, cost] : con[node]) {
            int ncost = tcost + cost;
            if (dist[to] > ncost) {
                dist[to] = ncost;
                q.push({ -ncost, to });
            }
        }
    }
    return 1e9;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        con[a].push_back({ b,c });
        con[b].push_back({ a,c });
    }
    int s, t; cin >> s >> t;
    cout << dijkstra(s, t);
}