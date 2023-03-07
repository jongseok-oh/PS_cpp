#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int parent[10001];
bool visit[10001];

vector<int> child[10001];

int getLca(int t) {
	if (parent[t] == -1 || visit[t]) return t;
	visit[t] = true;
	getLca(parent[t]);
}

int getSubTree(int t) {
	int ret = 1;
	for (int i = 0, len = child[t].size(); i < len; i++)
		ret += getSubTree(child[t][i]);
	return ret;
}

int main() {
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int v, e, a, b; cin >> v >> e >> a >> b;

		for (int i = 1; i <= v; i++) child[i].clear();
		memset(visit, 0, v + 1);

		parent[1] = -1;

		while (e--) {
			int p, c; cin >> p >> c;
			parent[c] = p;
			child[p].push_back(c);
		}
		getLca(a);
		int lca = getLca(b);

		int subTree = getSubTree(lca);
		cout << "#" << tt << " " << lca << " " << subTree << "\n";
	}
}