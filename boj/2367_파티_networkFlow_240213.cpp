#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, k, d;

int s, t;
int cap[302][302];
int flow[302][302];

vector<int> con[302];

void addEdge(int from, int to, int c) {
    cap[from][to] = c;
    con[from].push_back(to);
    con[to].push_back(from);
}

int parent[302];
int maxFlow() {

    int ret = 0;

    while (true) {
        memset(parent, -1, sizeof parent);

        queue<int> q;
        q.push(s);
        parent[s] = s;

        while (q.size() && parent[t] == -1)
        {
            int temp = q.front(); q.pop();

            for (int nNode : con[temp]) {
                if (parent[nNode] == -1 && cap[temp][nNode] - flow[temp][nNode] > 0) {
                    parent[nNode] = temp;
                    q.push(nNode);
                }
            }
        }

        if (parent[t] == -1) break;

        int amount = 1e9;
        for (int p = t; p != s; p = parent[p])
            amount = min(amount, cap[parent[p]][p] - flow[parent[p]][p]);

        ret += amount;

        for (int p = t; p != s; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> d;

    s = n + d, t = n + d + 1;

    int food;
    for (int i = 0; i < d; ++i) {
        cin >> food;
        addEdge(i + n, t, food);
    }

    int z;
    for (int i = 0; i < n; ++i) {
        addEdge(s, i, k);
        cin >> z;
        int fNum;
        for (int j = 0; j < z; ++j) {
            cin >> fNum;
            addEdge(i, n + fNum - 1, 1);
        }
    }
    cout << maxFlow();
}