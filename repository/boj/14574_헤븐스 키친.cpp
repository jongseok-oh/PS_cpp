#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int n;

struct edge { int i, j, w;};

int parent[1001], p[1001], c[1001];

edge edges[1000000];

bool visit[1001][1001] = { false, };

bool cmp(edge a, edge b) {return a.w > b.w;}

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

vector<int> idj[1001];
bool nodeVist[1001] = { false, };

void dfs(int cook) {
	nodeVist[cook] = true;
	for (int nCook : idj[cook]) {
		if (!nodeVist[nCook]) {
			dfs(nCook);
			cout << cook << " " << nCook << "\n";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <=n; i++) {
		cin >> p[i] >> c[i];
	}

	// make edge
	int edgeCnt = 0;
	for (int i = 1; i <=n; i++) for (int j = 1; j <=n; j++) {
		if (i == j) continue;
		if (visit[j][i]) continue;
		edges[edgeCnt++] = { i,j, (c[i] + c[j]) / abs(p[i] - p[j]) };
		visit[i][j] = true;
	}

	sort(edges, edges + edgeCnt, cmp);

	for (int i = 1; i <=n; i++) parent[i] = i;

	int cnt = 0; long long sum = 0;
	for (int i = 0; i < edgeCnt; i++) {
		edge t = edges[i];
		if (Union(t.i, t.j)) {
			sum += t.w;
			idj[t.i].push_back(t.j);
			idj[t.j].push_back(t.i);
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << sum<<"\n";

	dfs(1);
}