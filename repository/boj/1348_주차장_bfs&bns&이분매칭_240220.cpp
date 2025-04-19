#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int R,C;

int pCnt = 0;
int map[50][50];

struct Loc { int y, x; };
vector<Loc> cars;

struct Park { int num, len; };
vector<Park> con[101];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int qf, qe;
Loc q[3000];
bool visit[50][50];
void bfs(int carIdx) {
    memset(visit, 0, sizeof visit);
    qf = 0, qe = 0;

    auto [sy, sx] = cars[carIdx];

    q[qe++] = { sy,sx };
    visit[sy][sx] = true;

    int len = 1;
    while (qf < qe) {
        int qsize = qe - qf;
        while (qsize--) {
            auto [ty, tx] = q[qf++];

            for (int dir = 0; dir < 4; ++dir) {
                int ny = ty + dy[dir], nx = tx + dx[dir];

                if (ny < 0 || ny >= R || nx < 0 || nx >= C || visit[ny][nx]) continue;
                int mapNum = map[ny][nx];
                if (mapNum == -3) continue;
                visit[ny][nx] = true;

                if (mapNum >= 0) con[carIdx].push_back({ mapNum, len });
                
                q[qe++] = { ny,nx };
            }
        }
        ++len;
    }
}


int pMatching[100];

bool carVisit[100];
bool dfs(int car, int time) {
    if (carVisit[car]) return false;
    carVisit[car] = true;

    for (auto& [pNum, len] : con[car]) {
        if (len > time) continue;
        if (pMatching[pNum] == -1 || dfs(pMatching[pNum], time)) {
            pMatching[pNum] = car;
            return true;
        }
    }

    return false;
}


int matching(int time) {
    memset(pMatching, -1, 4 * pCnt);

    int ret = 0;
    for (int i = 0; i<cars.size(); ++i) {
        memset(carVisit, 0, cars.size());
        if (dfs(i, time)) ++ret;
    }

    return ret;
}


int binarySearch() {
    int low = 0, high = 2501;
    while (low + 1 < high) {
        int mid = (low + high) >> 1;
        if (matching(mid) >= cars.size()) high = mid;
        else low = mid;
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R>>C;

    char c;
    for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
        cin >> c;
        if (c == 'C') { cars.push_back({ i,j }); map[i][j] = -1; }
        else if (c == 'P') map[i][j] = pCnt++;
        else if (c == 'X') map[i][j] = -3;
        else map[i][j] = -2;
    }

    if (!cars.size()) {
        cout << 0; return 0;
    }

    for (int i = 0; i < cars.size(); ++i) bfs(i);

    int ret =  binarySearch();
    cout << (ret == 2501 ? -1 : ret);
}