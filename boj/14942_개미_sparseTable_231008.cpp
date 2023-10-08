#include <iostream>
#include <vector>

using namespace std;

const int _MAX = 17;

int n;

int ants[100001];

struct edge { int node, cost; };

vector<edge> con[100001];

int parent[100001][_MAX];
int table[100001][_MAX];

void dfs(int tNode) {
	for (auto& eg : con[tNode]) {
		int nNode = eg.node;

		if (nNode != 1 && !parent[nNode][0]) {
			parent[nNode][0] = tNode;
			table[nNode][0] = eg.cost;
			dfs(nNode);
		}
	}
}

int solve(int tNode) {
	int p = tNode, energy = ants[tNode];

	while (p != 1 && energy) {
		bool find = false;
		for (int bit = _MAX - 1; bit >= 0; --bit) {
			if (parent[p][bit] && table[p][bit] <= energy) {
				energy -= table[p][bit];
				p = parent[p][bit];

				find = true; break;
			}
		}

		if (!find) break;
	}

	return p;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; ++i) cin >> ants[i];

	int a, b, c;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		con[a].push_back({ b,c });
		con[b].push_back({ a,c });
	}
	dfs(1);
	
	for (int bit = 1; bit < _MAX; ++bit) for (int node = 2; node <= n; ++node) {
		int tParent = parent[node][bit - 1];
		int grandParent = parent[tParent][bit-1];

		if (grandParent) {
			parent[node][bit] = grandParent;
			table[node][bit] = table[node][bit - 1] + table[tParent][bit - 1];
		}
	}

	for (int i = 1; i <= n; i++) cout << solve(i) << "\n";
}