#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Loc = pair<int, int>;

int n, m;
const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
void meltIceberg(vector<vector<int>>& iceberg) {
    vector<vector<int>> zeroCounts(n, vector<int>(m));
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < m-1; ++j) {
            if (iceberg[i][j] == 0) continue;

            for (int dir = 0; dir < 4; ++dir) {
                int ny = i + dy[dir], nx = j + dx[dir];
                if (iceberg[ny][nx] == 0) ++zeroCounts[i][j];
            }
        }
    }

    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < m-1; ++j) {
            if (iceberg[i][j] == 0) continue;
            int calc = iceberg[i][j] - zeroCounts[i][j];
            iceberg[i][j] = (calc < 0 ? 0 : calc);
        }
    }
}

void bfs(Loc start, vector<vector<int>>& iceberg, vector<vector<bool>>& visit) {
    queue<Loc> q;
    q.push(start);
    visit[start.first][start.second] = true;

    while (q.size()) {
        auto [y, x] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if (iceberg[ny][nx] == 0 || visit[ny][nx]) continue;

            visit[ny][nx] = true;
            q.emplace(ny, nx);
        }
    }
}
int countIsland(vector<vector<int>>& iceberg) {
    vector<vector<bool>> visit(n, vector<bool>(m));

    int count = 0;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < m-1; ++j) {
            if (iceberg[i][j] != 0 && !visit[i][j]) {
                bfs({ i,j }, iceberg, visit);
                ++count;
            }
        }
    }

    return count;
}

int solve(vector<vector<int>>& iceberg) {
    int time = 0;
    while (true) {
        int count = countIsland(iceberg);
        if (count >= 2) break;
        if (count == 0) return 0;
        meltIceberg(iceberg);
        ++time;
    }
    return time;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    vector<vector<int>> iceberg(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> iceberg[i][j];
        }
    }

    cout << solve(iceberg);
}