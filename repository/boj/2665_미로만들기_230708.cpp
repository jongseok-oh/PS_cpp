#include <iostream>
#include <queue>

using namespace std;

int n;

string map[50];
int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

struct Loc { int y, x; };
struct Node {
	int y,x,cost;
	bool operator < (const Node& a) const {
		return cost > a.cost;
	}
};

int dist[50][50];
int dijkstra() {
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		dist[i][j] = 1e9;

	dist[0][0] = 1;

	priority_queue<Node> q;
	q.push({ 0,0,0 });

	while (q.size())
	{
		auto t = q.top(); q.pop();
		int y = t.y, x = t.x, cost = t.cost;

		if (y == n - 1 && x == n - 1) return cost;

		if (dist[y][x] < cost) continue;

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir], nx = x + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			int nCost = cost + (map[ny][nx] == '0');
			
			if (dist[ny][nx] > nCost) {
				dist[ny][nx] = nCost;
				q.push({ ny,nx,nCost });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> map[i];

	cout << dijkstra();
}