#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define y first
#define x second
typedef pair<int, int> Loc;
struct Edge {
    Loc to;
    int cap, rev;
};

int n, m;
Loc s = {50, 0}, t = {50,1};
vector<Edge> network[51][50];

void addEdge(Loc from, Loc to, int cap) {
    network[from.y][from.x].push_back({ to, cap, (int)network[to.y][to.x].size() });
    network[to.y][to.x].push_back({ from, 0, (int)network[from.y][from.x].size()-1});
}

int board[50][50];
int init() {
    cin >> n >> m;
    network[s.y][s.x].clear(); network[t.y][t.x].clear();
    
    int sum = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        network[i][j].clear();
        cin >> board[i][j];
        sum += board[i][j];
    }

    return sum;
}

const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
void makeNetwork() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if ((i + j) & 1) {
            addEdge(s, { i,j }, board[i][j]);
            for (int dir = 0; dir < 4; ++dir) {
                int ny = i + dy[dir], nx = j + dx[dir];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                addEdge({ i,j }, { ny,nx }, 1e9);
            }
        }
        else addEdge({ i,j }, t, board[i][j]);
    }
}

bool visit[51][50];
int dfs(Loc node, int f) {
    if (node == t) return f;

    visit[node.y][node.x] = true;
    for (Edge& loc : network[node.y][node.x]) {
        if (!visit[loc.to.y][loc.to.x] && loc.cap > 0) {
            int d = dfs(loc.to, min(f, loc.cap));
            if (d > 0) {
                loc.cap -= d;
                network[loc.to.y][loc.to.x][loc.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int flow = 0;
    while (true) {
        memset(visit, 0, sizeof visit);
        int f = dfs(s, 1e9);
        if (f == 0) return flow;
        flow += f;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int sum = init();
        makeNetwork();
        cout << sum - maxFlow() << "\n";
    }
}