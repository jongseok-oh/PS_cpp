#include <iostream>
#include <vector>

using namespace std;

int n, c, q;
vector<int> con[200001];

int startNode[200001];
int endNode[200001];
int depth[200001];
int tree[800000];

void setNodeRange(int t, int& nodeNum) {
	startNode[t] = ++nodeNum;
	for (int& next : con[t]) {
		if (startNode[next]) continue;
		depth[next] = depth[t] + 1;
		setNodeRange(next, nodeNum);
	}
	endNode[t] = nodeNum;
}

void _update(int node, int l, int r, int t) {
	if (l > t || r < t) return;
	if (l == r) { ++tree[node]; return; }
	int mid = (l + r) >> 1;
	_update(node * 2, l, mid, t);
	_update(node * 2 + 1, mid + 1, r, t);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int _search(int node, int l, int r, int s, int e) {
	if (l > e || r < s) return 0;
	if (s <= l && e >= r) return tree[node];
	int mid = (l + r) >> 1;
	return 	_search(node * 2, l, mid, s, e) + _search(node * 2 + 1, mid+1, r, s, e);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> c;

	int x, y;
	for (int i = 0; i < n - 1; ++i) {
		cin >> x >> y;
		con[x].push_back(y);
		con[y].push_back(x);
	}
	
	int nodeNum = 0;
	depth[c] = 1; setNodeRange(c, nodeNum);

	cin >> q;
	while (q--) {
		int mode, node;
		cin >> mode >> node;
		if (mode == 1) _update(1, 1, n, startNode[node]);
		else cout << (1LL * _search(1, 1, n, startNode[node], endNode[node]) * depth[node]) << "\n";
	}
}