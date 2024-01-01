#include <iostream>
#include <vector>

using namespace std;

int n, m;

int salary[500001];
vector<int> con[500001];

struct Range {
	int start, end;
}nodeRange[500001];

void setRange(int t, int& nodeNum) {
	nodeRange[t].start = ++nodeNum;
	for (int& nNode : con[t]) {
		setRange(nNode, nodeNum);
	}
	nodeRange[t].end = nodeNum;
}

int lazyTree[2000000];
void updateLazy(int node, int l, int r) {
	if (lazyTree[node]) {
		if (l != r) {
			lazyTree[node * 2] += lazyTree[node];
			lazyTree[node * 2 + 1] += lazyTree[node];
		}
		lazyTree[node] = 0;
	}
}

void _update(int node, int l, int r, int s, int e, int v) {
	if (l > e || r < s) return;
	if (s <= l && e >= r) {
		lazyTree[node] += v; return;
	}
	updateLazy(node, l, r);
	int mid = (l + r) >> 1;
	_update(node * 2, l, mid, s, e, v);
	_update(node * 2 + 1, mid+1, r, s, e, v);
}

int getSalary(int node, int l, int r, int idx) {
	int t = nodeRange[idx].start;
	if (l > t || r < t) return 0;
	if (l == r) {
		salary[idx] += lazyTree[node];
		lazyTree[node] = 0;
		return salary[idx];
	}
	updateLazy(node, l, r);
	int mid = (l + r) >> 1;
	return getSalary(node * 2, l, mid, idx) + getSalary(node * 2 + 1, mid + 1, r, idx);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	
	cin >> salary[1];
	int sup;
	for (int i = 2; i <= n; ++i) {
		cin >> salary[i]>> sup;
		con[sup].push_back(i);
	}
	int nodeNum = 0;
	setRange(1, nodeNum);

	while (m--) {
		char mode; cin >> mode;
		int a, x; cin >> a;
		if (mode == 'p') {
			cin >> x;
			int s = nodeRange[a].start, e = nodeRange[a].end;
			// 자기 자신 제외하고
			if (s < e) _update(1, 1, n, s + 1, e, x);
		}
		else cout << getSalary(1, 1, n, a) << "\n";
	}
}