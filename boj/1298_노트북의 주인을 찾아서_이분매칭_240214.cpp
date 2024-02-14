#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

bool con[101][101];
bool visit[101];

int aMatch[101], bMatch[101];

bool dfs(int t) {
    if (visit[t]) return false;
    visit[t] = true;

    for (int b = 1; b <= n; ++b) {
        if (con[t][b]) {
            if (!bMatch[b] || dfs(bMatch[b])) {
                aMatch[t] = b;
                bMatch[b] = t;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        con[a][b] = true;
    }

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        memset(visit, 0, n + 1);
        if (dfs(i)) ++ret;
    }
        
    cout << ret;
}