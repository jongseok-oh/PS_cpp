#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

#define _min first
#define _max second

int T,n,k,q,a,b;

int disk[100000];
Pair tree[400000];

void init(int node, int l, int r) {
	if (l == r) {
		tree[node]._min = l;
		tree[node]._max = r;
		return;
	}
	int mid = (l + r) >> 1;
	init(node * 2, l, mid);
	init(node * 2 + 1, mid + 1, r);
	tree[node]._min = tree[node * 2]._min;
	tree[node]._max = tree[node * 2 + 1]._max;
}

Pair query(int node, int r, int l, int s, int e) {
	if (r > e || l < s) return { 1e9, -1 };
	if (r <= s && l >= e) return tree[node];
	int mid = (s + e) >> 1;
	Pair left = query(node * 2, r, l, s, mid);
	Pair right = query(node * 2 + 1, r, l, mid+1, e);
	return { min(left._min, right._min), max(left._max, right._max) };
}

void _update(int node, int val, int idx, int s, int e) {
	if (idx > e || idx < s) return;
	if (s == e) {
		tree[node]._min = val;
		tree[node]._max = val;
		return;
	}
	int mid = (s + e) >> 1;
	_update(node * 2, val, idx, s, mid);
	_update(node * 2 + 1, val, idx, mid+1, e);
	tree[node]._min = min(tree[node * 2]._min, tree[node * 2 + 1]._min);
	tree[node]._max = max(tree[node * 2]._max, tree[node * 2 + 1]._max);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n>>k;
		for (int i = 0; i < n; ++i) disk[i] = i;
		init(1, 0, n - 1);

		while (k--) {
			cin >> q >> a >> b;
			if (q) {
				Pair p = query(1, a, b, 0, n - 1);
				cout << (a == p._min && b == p._max ? "YES\n" : "NO\n");
			}
			else {
				swap(disk[a], disk[b]);
				_update(1, disk[a], a, 0, n - 1);
				_update(1, disk[b], b, 0, n - 1);
			}
		}
	}
}