#include <iostream>
#include <vector>
#include <cstring>

#define _MAX 17

using namespace std;

typedef pair<int, int> pii;

int n,m;

vector<pii> edges[40001];
int depth[40001];
int dist[40001][_MAX];
int parent[40001][_MAX];

void dfs(int t) {
	for (pii& next : edges[t]) {
		int nNode = next.first;
		if (depth[nNode] != -1) continue;
		depth[nNode] = depth[t] + 1;

		parent[nNode][0] = t;
		dist[nNode][0] = next.second;
		dfs(nNode);
	}
}

int getLen(int tar, int val) {
	int ret = 0;
	if (depth[tar] > depth[val]) swap(tar, val);

	if (depth[tar] != depth[val]) {
		for (int i = _MAX - 1; i >= 0; i--) {
			if (depth[parent[val][i]] >= depth[tar])
			{
				ret += dist[val][i];
				val = parent[val][i];
			}
			if (depth[val] == depth[tar]) break;
		}
	}

	if (tar == val) return ret;

	for (int i = _MAX - 1; i >= 0; i--) {
		if (parent[val][i] != parent[tar][i]) {
			ret += dist[val][i] + dist[tar][i];
			val = parent[val][i];
			tar = parent[tar][i];
		}
	}
	return ret + dist[val][0] + dist[tar][0];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}
	memset(depth, -1, 4 * (n + 1));
	depth[1] = 0;
	dfs(1);

	for (int j = 0; j < _MAX; j++) for (int i = 1; i <= n; i++)
		if (parent[i][j]) {
			parent[i][j + 1] = parent[parent[i][j]][j];
			dist[i][j + 1] = dist[parent[i][j]][j] + dist[i][j];
		}
	
	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << getLen(a, b) << "\n";
	}
}
