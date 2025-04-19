#include <iostream>
#include <algorithm>

using namespace std;

int n;

int forest[500][500];

int dp[500][500];

int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };

int solve(int y, int x) {
    int& ret = dp[y][x];
    if (ret != 0) return ret;
    ret = 1;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir],
            nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (forest[ny][nx] <= forest[y][x]) continue;

        ret = max(ret, solve(ny, nx) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> forest[i][j];

    int ans = 1;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        ans = max(ans, solve(i, j));
   }
    cout << ans;
}