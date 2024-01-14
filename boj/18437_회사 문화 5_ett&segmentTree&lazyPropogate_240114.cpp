#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> con[100001];

int s[100001], e[100001];
void dfs(int t, int& order) {
	s[t] = ++order;
	for (int node : con[t]) dfs(node, order);
	e[t] = order;
}

int lazyTree[400000];
int segTree[400000];
void updateLazy(int node, int l, int r) {
	if (lazyTree[node]) {
		if (l != r) { lazyTree[node * 2] = lazyTree[node * 2 + 1] = lazyTree[node]; }
		segTree[node] = (lazyTree[node] == 1 ? r - l + 1 : 0);
		lazyTree[node] = 0;
	}
}

void set(int node, int l, int r, int start, int end, int val) {
	updateLazy(node, l, r);
	if (start > r || end < l) return;
	if (start <= l && end >= r) {
		lazyTree[node] = val;
		updateLazy(node, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	set(node * 2, l, mid, start, end, val);
	set(node * 2 + 1, mid+1, r, start, end, val);
	segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int get(int node, int l, int r, int start, int end) {
	if (start > r || end < l) return 0;
	updateLazy(node, l, r);
	if (start <= l && end >= r) return segTree[node];
	int mid = (l + r) >> 1;
	return get(node * 2, l, mid, start, end) + get(node * 2 + 1, mid + 1, r, start, end);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int p;
	for (int i = 1; i <= n; ++i) {
		cin >> p; con[p].push_back(i);
	}
	int order = 0; dfs(1, order);
	lazyTree[1] = 1;
	cin >> m;
	int q, num;
	while (m--) {
		cin >> q >> num;
		// leaf가 아닌 직원만
		if (q == 1) { if (s[num] != e[num]) set(1, 1, n, s[num] + 1, e[num], 1); }
		else if (q == 2) { if(s[num] != e[num]) set(1, 1, n, s[num] + 1, e[num], -1);}
		else cout << ((s[num] == e[num]) ? 0 : get(1, 1, n, s[num] + 1, e[num])) << "\n";
	}
}