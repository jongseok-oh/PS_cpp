#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int price[5][5] = {
	{10,8,7,5,1},
	{8,6,4,3,1},
	{7,4,3,2,1},
	{5,3,2,2,1},
	{1,1,1,1,0}
};

#define y first
#define x second
typedef pair<int, int> Loc;

int n, m;
Loc s = { 50, 0 }, t = {50,1};
int board[50][50];

struct Edge {
	Loc to;
	int cap, rev, cost;
};

vector<Edge> con[51][50];
void addEdge(Loc from, Loc to, int cap, int cost) {
	con[from.y][from.x].push_back({ to, cap, (int)con[to.y][to.x].size(),cost });
	con[to.y][to.x].push_back({ from, 0, (int)con[from.y][from.x].size()-1,-cost });
}

void makeGraph() {
	const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		addEdge({ i,j }, t, 1, 0);
		if ((i + j) % 2 == 0) {
			addEdge(s, { i,j }, 1, 0);
			for (int dir = 0; dir < 4; ++dir) {
				int ny = i + dy[dir], nx = j + dx[dir];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				addEdge({ i,j }, {ny,nx}, 1e9, -price[board[i][j]][board[ny][nx]]);
			}
		}
	}
}

const int INF = 0x3f3f3f3f;
int dist[51][50];
bool inQ[51][50];
Loc parent[51][50];
int preve[51][50];
int spfa() {
	memset(dist, 0x3f, sizeof dist);
	memset(inQ, 0, sizeof inQ);

	queue<Loc> q; q.push(s);
	inQ[s.y][s.x] = true;
	dist[s.y][s.x] = 0;

	while (q.size()) {
		Loc loc = q.front(); q.pop();
		inQ[loc.y][loc.x] = false;
		for (int i = 0, n = con[loc.y][loc.x].size(); i < n; ++i) {
			Edge& edge = con[loc.y][loc.x][i];
			Loc to = edge.to;
			if (edge.cap > 0 && dist[to.y][to.x] > dist[loc.y][loc.x] + edge.cost) {
				dist[to.y][to.x] = dist[loc.y][loc.x] + edge.cost;
				parent[to.y][to.x] = loc;
				preve[to.y][to.x] = i;
				if (!inQ[to.y][to.x]) {
					q.push(to);
					inQ[to.y][to.x] = true;
				}
			}
		}
	}
	return dist[t.y][t.x];
}


int mcmf(){
	int ret = 0, f;
	while ((f = spfa()) != INF) {
		for (Loc i = t; i != s; i = parent[i.y][i.x]) {
			Loc p = parent[i.y][i.x];
			Edge& edge = con[p.y][p.x][preve[i.y][i.x]];
			edge.cap--;
			con[i.y][i.x][edge.rev].cap++;
		}
		ret += f;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		char rank;
		for (int j = 0; j < m; ++j) {
			cin >> rank; if (rank == 'F') rank = 'E';
			board[i][j] = rank - 'A';
		}
	}
	makeGraph();
	cout << -mcmf();
}