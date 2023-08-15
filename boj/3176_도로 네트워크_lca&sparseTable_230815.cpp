#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int _MAX = 100001;
const int MAX_BIT = 18;

int N, K;

struct Edge { int nNode, cost;};

vector<Edge> con[_MAX];

int depth[_MAX];
int parent[_MAX][MAX_BIT];
int minEdge[_MAX][MAX_BIT];
int maxEdge[_MAX][MAX_BIT];

void dfs(int tNode) {
	for (auto& nEdge : con[tNode]) {

		int nNode = nEdge.nNode;
		int nCost = nEdge.cost;

		if (nNode != 1 && !depth[nNode]) {

			depth[nNode] = depth[tNode] + 1;

			parent[nNode][0] = tNode;
			minEdge[nNode][0] = nCost;
			maxEdge[nNode][0] = nCost;

			dfs(nNode);
		}
	}
}

void LCA(int d, int e, int& shortEdge, int& longEdge) {
	// d가 더 길게 설정
	if (depth[d] < depth[e]) swap(d, e);

	int tDepth = depth[d];

	if (tDepth != depth[e]) {
		// 길이 맞추기
		for (int i = MAX_BIT - 1; i >= 0; i--) {
			if (tDepth - (1 << i) >= depth[e]) {
				tDepth -= (1 << i);

				shortEdge = min(minEdge[d][i], shortEdge);
				longEdge = max(maxEdge[d][i], longEdge);
				d = parent[d][i];
			}
		}
	}

	// e가 조상인 경우
	if (d == e) return;

	for (int i = MAX_BIT - 1; i >= 0; i--) {
		if (parent[d][i] != parent[e][i]) {

			shortEdge = min({ minEdge[d][i], minEdge[e][i],shortEdge});
			longEdge = max({ maxEdge[d][i], maxEdge[e][i], longEdge });
			d = parent[d][i];
			e = parent[e][i];
		}
	}

	shortEdge = min({ minEdge[d][0], minEdge[e][0],shortEdge });
	longEdge = max({ maxEdge[d][0], maxEdge[e][0], longEdge });
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b, c; cin >> a >> b >> c;

		con[a].push_back({ b,c });
		con[b].push_back({ a,c });
	}

	dfs(1);

	// parse table
	for (int i = 1; i < MAX_BIT; i++) for (int j = 2; j < _MAX; j++) {

		int tParent = parent[j][i - 1];
		if (!tParent) continue;

		parent[j][i] = parent[tParent][i - 1];
		if (!parent[j][i]) continue;

		minEdge[j][i] = min(minEdge[tParent][i - 1], minEdge[j][i - 1]);
		maxEdge[j][i] = max(maxEdge[tParent][i - 1], maxEdge[j][i - 1]);
	}

	cin >> K;
	while (K--) {
		int D, E; cin >> D >> E;
		
		int shortEdge = 1e9, longEdge = -1;
		LCA(D, E, shortEdge, longEdge);

		cout << shortEdge << " " << longEdge << "\n";
	}
}