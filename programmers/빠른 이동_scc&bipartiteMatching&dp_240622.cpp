#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> con[501];
vector<int> rcon[501];

vector<int> order;
bool visit[501];
void dfs(int v) {
    visit[v] = true;
    for (int next : con[v]) {
        if (!visit[next]) dfs(next);
    }
    order.push_back(v);
}

int cmp[501];
void rdfs(int v, int k) {
    visit[v] = true;
    cmp[v] = k;
    for (int next : rcon[v]) {
        if (!visit[next]) rdfs(next, k);
    }
}
bool edgeVisit[501][501];
vector<vector<int>> scc(int n, vector<vector<int>>& roads) {
    for (auto& road : roads) {
        int a = road[0], b = road[1];
        con[a].push_back(b);
        rcon[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) dfs(i);
    }

    int k = 0;
    memset(visit, 0, sizeof visit);
    for (auto it = order.rbegin(); it != order.rend(); ++it) {
        int v = *it;
        if (!visit[v]) rdfs(v, k++);
    }
    vector<vector<int>> sccCon(k);
    for (int i = 1; i <= n; ++i) {
        for (int next : con[i]) {
            int tCmp = cmp[i], nCmp = cmp[next];
            if (!edgeVisit[tCmp][nCmp] && tCmp != nCmp) {
                sccCon[tCmp].push_back(nCmp);
                edgeVisit[tCmp][nCmp] = true;
            }
        }
    }

    return sccCon;
}

int s = 1013, t = 1014;
struct Edge { int to, cap, rev; };
vector<Edge> dagCon[1030];
void addEdge(int from, int to, int cap) {
    dagCon[from].push_back({ to, cap, (int)dagCon[to].size() });
    dagCon[to].push_back({ from, 0, (int)dagCon[from].size() - 1 });
}

int level[1030];
bool bfs() {
    memset(level, -1, sizeof level);
    queue<int> q; q.push(s);
    level[s] = 0;
    while (q.size()) {
        int node = q.front(); q.pop();
        for (Edge& edge : dagCon[node]) {
            if (edge.cap > 0 && level[edge.to] == -1) {
                level[edge.to] = level[node] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

int iter[1030];
bool tdfs(int v) {
    if (v == t) return true;
    for (int& i = iter[v]; i < dagCon[v].size(); ++i) {
        Edge& edge = dagCon[v][i];
        if (edge.cap > 0 && level[v] < level[edge.to]) {
            if (tdfs(edge.to)) {
                edge.cap--;
                dagCon[edge.to][edge.rev].cap++;
                return true;
            }
        }
    }
    return false;
}

int dinic() {
    int ret = 0;
    while (bfs()) {
        memset(iter, 0, sizeof iter);
        while (tdfs(s)) ++ret;
    }
    return ret;
}

unordered_set<int> dp[500];
unordered_set<int> generateEdge(int v, int k, vector<vector<int>>& con) {
    unordered_set<int>& childs = dp[v];
    if(childs.size()) return childs;
    for (int child : con[v]) {
        unordered_set<int> t = generateEdge(child, k, con);
        childs.insert(t.begin(), t.end());
    }
    for (int child : childs) {
        addEdge(v + k, child, 1);
    }
    childs.insert(v);
    return childs;
}

int minPath(vector<vector<int>> con) {
    int k = con.size();
    for (int i = 0; i < k; ++i) {
        if (dagCon[i+k].size() == 0) generateEdge(i, k, con);
        addEdge(s, i + k, 1);
        addEdge(i, t, 1);
    }

    return k - dinic();
}

int solution(int n, vector<vector<int>> roads) {
    return minPath(scc(n, roads)) - 1;
}