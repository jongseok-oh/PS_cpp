#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
vector<int> con[1000];

bool visit[1000];
int vMatch[1000];
bool dfs(int t) {
    if (visit[t]) return false;
    visit[t] = true;

    for (int v : con[t]) {
        if (vMatch[v] == -1 || dfs(vMatch[v])) {
            vMatch[v] = t;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        
        for (int i = 0; i < n; ++i) con[i].clear();

        int u, v;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            con[u].push_back(v);
        }

        memset(vMatch, -1, 4 * n);

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            memset(visit, 0, n);
            if (dfs(i)) ++ret;
        }
        cout << ret << "\n";
    }
}