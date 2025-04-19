#include <iostream>
#include <vector>
#include <cstring>

#define _MAX 17

using namespace std;

int n, m;

vector<int> edges[50001];
int depth[50001];
int parent[50001][_MAX];

void dfs(int t) {
	for (int& next : edges[t]) {
		if (depth[next] != -1) continue;
		depth[next] = depth[t] + 1;
		parent[next][0] = t;
		dfs(next);
	}
}

int search(int tar, int val) {
	if (depth[tar] > depth[val]) swap(tar, val);

	if (depth[tar] != depth[val]) {
		for (int i = _MAX - 1; i >= 0; i--) {
			if (depth[parent[val][i]] >= depth[tar])
			{
				val = parent[val][i];
				if (depth[val] == depth[tar]) break;
			}
		}
	}
	if (tar == val) return tar;

	for (int i = _MAX - 1; i >= 0; i--) {
		if (parent[tar][i] != parent[val][i]) {
			tar = parent[tar][i];
			val = parent[val][i];
		}
	}

	return parent[tar][0];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	memset(depth, -1, 4 * (n+1));
	depth[1] = 0;
	dfs(1);

	for (int j = 0; j < _MAX; j++) for (int i = 1; i <= n; i++)
		if (parent[i][j]) parent[i][j + 1] = parent[parent[i][j]][j];

	cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << search(a, b) << "\n";
	}
}