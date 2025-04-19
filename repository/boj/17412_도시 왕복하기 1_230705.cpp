#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, p;

bool cap[400][400];
int flow[400][400];

vector<int> con[400];

int level[400];
bool bfs() {
	memset(level, -1, 4 * n);

	queue<int> q;
	q.push(0);
	level[0] = 0;
	int depth = 1;
	while (q.size())
	{
		int qsize = q.size();
		while (qsize--)
		{
			int t = q.front(); q.pop();
			if (t == 1) return true;

			for (int next : con[t]) {
				if (level[next] == -1 && cap[t][next] - flow[t][next] > 0) {
					level[next] = depth;
					q.push(next);
				}
			}
		}
		depth++;
	}

	return false;
}

bool dfs(int t) {
	if (t == 1) return true;
	for (int& next : con[t]) {
		if (level[t] + 1 == level[next] && cap[t][next] - flow[t][next] > 0) {
			if (dfs(next)) {
				flow[t][next]++;
				flow[next][t]--;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> p;
	
	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		--a; --b;
		con[a].push_back(b);
		con[b].push_back(a);
		cap[a][b] = 1;
	}

	int ans = 0;
	while (bfs()){ dfs(0); ans++;}
	cout << ans;
}