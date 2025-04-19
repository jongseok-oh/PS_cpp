#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
struct Edge { int to, cap, rev; };
vector<Edge> con[410];

void addEdge(int from, int to, int cap) {
    con[from].push_back({ to, cap, (int)con[to].size() });
    con[to].push_back({ from, 0, (int)con[from].size()-1});
}

int s, t;

int level[410];
bool bfs() {
    memset(level, -1, sizeof level);
    level[s] = 0;
    queue<int> q; q.push(s);
    while (q.size())
    {
        int node = q.front(); q.pop();
        for (auto& edge : con[node]) {
            if (edge.cap > 0 && level[edge.to] == -1) {
                level[edge.to] = level[node] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

int iter[410];
int dfs(int node, int f) {
    if (node == t) return f;
    for (int& i = iter[node], n = con[node].size(); i < n; ++i) {
        Edge& edge = con[node][i];
        if (level[node] < level[edge.to] && edge.cap > 0) {
            int d = dfs(edge.to, min(f, edge.cap));
            if (d > 0) {
                edge.cap -= d;
                con[edge.to][edge.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

void dinic() {
    while (bfs())
    {
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, 1e9)) > 0);
    }
}

bool visit[410];
void solve() {
    queue<int> q;
    q.push(s); visit[s] = true;
    while (q.size()) {
        int node = q.front(); q.pop();
        for (Edge& edge : con[node]) {
            if (edge.cap > 0 && !visit[edge.to]) {
                visit[edge.to] = true;
                q.push(edge.to);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (visit[i] && !visit[i + n]) {
            cout << i + 1<< " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    t += n;
    --s; --t;
    for (int i = 0; i < n; ++i) {
        int money; cin >> money;
        addEdge(i, i + n, money);
    }

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a; --b;
        addEdge(a + n, b, 1e9);
        addEdge(b + n, a, 1e9);
    }
    dinic();
    solve();
}