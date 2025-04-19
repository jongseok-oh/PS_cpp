#include <iostream>
#include <algorithm>

using namespace std;

int n, p;

struct edge { int i, j, w;};

int country[10000];

edge edges[100000];

int parent[10000];

bool cmp(edge a, edge b) {return a.w < b.w;}

int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]);
}

bool Union(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA == rootB) return false;
	parent[rootB] = rootA;
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> p;

	int _min = 1001;
	for (int i = 0; i < n; i++) {
		cin >> country[i];
		_min = _min > country[i] ? country[i] : _min;
	}
	for (int i = 0; i < p; i++) {
		int s, e, l; cin >> s >> e >> l; s--; e--;

		edges[i] = { s,e, l * 2 + country[s] + country[e] };
	}

	sort(edges, edges + p, cmp);

	for (int i = 0; i < n; i++) parent[i] = i;

	int cnt = 0, cost = 0;
	for (int i = 0; i < p; i++) {
		edge t = edges[i];
		if (Union(t.i, t.j)) {
			cost += t.w;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << cost+_min;
}