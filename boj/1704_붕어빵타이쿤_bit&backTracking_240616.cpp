#include <iostream>
#include <cstring>

using namespace std;

int n, m;
bool map[15][15], temp[15][15], flip[15][15], ans[15][15];

void init() {
    memcpy(temp, map, sizeof map);
    memset(flip, 0, sizeof flip);
}

int dy[] = { 1,-1,0,0,0 }, dx[] = { 0,0,1,-1,0 };
void click(int y, int x) {
    flip[y][x] = true;
    for (int dir = 0; dir < 5; ++dir) {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        temp[ny][nx] ^= 1;
    }
}

int solve(int cnt) {
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (temp[i - 1][j]) {
                click(i, j); cnt++;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        if (temp[n - 1][j]) return 1e9;
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
        cin >> map[i][j];

    int ret = 1e9;
    for (int i = 0, bit = 1 << m; i < bit; ++i) {
        init();
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                click(0, m - j - 1);
                ++cnt;
            }
        }
        cnt = solve(cnt);
        if (ret > cnt) {
            ret = cnt;
            memcpy(ans, flip, sizeof ans);
        }
    }

    if(ret == 1e9) cout << "IMPOSSIBLE";
    else {
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] << (j == m-1?"\n":" ");
            }
        }
    }
}