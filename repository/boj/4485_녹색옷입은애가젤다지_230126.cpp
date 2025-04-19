#include <iostream>
#include <queue>

using namespace std;

struct loc {
	int r, c, cost;
	bool operator < (loc a) const {
		return cost > a.cost;
	}
};

int n, problem;

int map[125][125];
int dist[125][125];

int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> n;
		if (!n) break;
		problem++;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			dist[i][j] = 1e9;
		}
		priority_queue<loc> q;
		dist[0][0] = map[0][0];
		q.push({ 0,0, map[0][0]});
		while (q.size()) {
			loc t = q.top(); q.pop();
			int tr = t.r,
				tc = t.c,
				tcost = t.cost;
			if (tr == n - 1 && tc == n - 1) {
				cout << "Problem " << problem << ": " << tcost << "\n";
				break;
			}
			if (dist[tr][tc] < tcost) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nr = tr + dy[dir],
					nc = tc + dx[dir];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				int ncost = tcost + map[nr][nc];
				if (dist[nr][nc] > ncost) {
					dist[nr][nc] = ncost;
					q.push({ nr, nc,ncost });
				}
			}
		}
	}

}