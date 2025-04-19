#include <iostream>

using namespace std;

int n, m;

int lazyTree[2000000];

int arr[500000];

void updateLazy(int start, int end, int node) {
	if (lazyTree[node] && start != end) {
		lazyTree[node * 2] ^= lazyTree[node];
		lazyTree[node * 2 + 1] ^= lazyTree[node];
		lazyTree[node] = 0;
	}
}

void update(int node, int left, int right, int val, int start, int end) {
	if (left > end || right < start) return;
	if (left <= start && right >= end) {
		lazyTree[node] ^= val;
		return;
	}
	int mid = (start + end) >> 1;
	update(node * 2, left, right, val, start, mid);
	update(node * 2 + 1, left, right, val, mid + 1, end);
}

int getNum(int node, int idx, int start, int end) {
	updateLazy(start, end, node);
	if (start > idx || end < idx) return 0;
	if (start == idx && end == idx) return lazyTree[node] ^ arr[idx];
	int mid = (start + end) >> 1;
	return getNum(node * 2, idx, start, mid) + getNum(node * 2 + 1, idx, mid + 1, end);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cin >> m;
	while (m--) {
		int t; cin >> t;
		if (t == 1) {
			int a, b, c; cin >> a >> b >> c;
			update(1, a, b, c, 0, n - 1);
		}
		else {
			int idx; cin >> idx;
			cout << getNum(1, idx, 0, n - 1) << "\n";
		}
	}
}