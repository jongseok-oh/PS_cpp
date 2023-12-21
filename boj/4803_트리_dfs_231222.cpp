#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
vector<int> con[501];
bool visit[501];

bool dfs(int tNode, int prev) {
    visit[tNode] = true;

    for (int& nNode : con[tNode]) {
        if (nNode == prev) continue;
        if (visit[nNode] || dfs(nNode, tNode)) return true;
    }
        

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tCase = 0;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        
        ++tCase;
        memset(visit, false, n + 1);
        for (int i = 1; i <= n; ++i) con[i].clear();

        int a, b;
        while (m--) {
            cin >> a >> b;
            con[a].push_back(b);
            con[b].push_back(a);
        }

        int ret = 0;
        for (int i = 1; i <= n; ++i)
            if (!visit[i] && !dfs(i, -1)) ret++;

        cout << "Case " << tCase << ": ";
        if (ret == 0) cout << "No trees.\n";
        else if (ret == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ret << " trees.\n";
    }
}