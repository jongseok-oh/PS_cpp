#include <iostream>

using namespace std;

typedef long long ll;

int n, Q;
ll arr[100001];
ll lazyTree[400000];
int lazyCnt[400000];

void updateLazy(int node, int s, int e) {
	if (lazyTree[node]) {
		if (s == e) arr[s] += 1LL*(s + 1) * lazyCnt[node] - lazyTree[node];
		else {
			lazyTree[node * 2] += lazyTree[node];
			lazyTree[node * 2 + 1] += lazyTree[node];
            lazyCnt[node * 2] += lazyCnt[node];
            lazyCnt[node * 2 + 1] += lazyCnt[node];
		}
		lazyTree[node] = 0;
        lazyCnt[node] = 0;
	}
}

void setLazy(int node, int l, int r, int s, int e) {
	if (l > e || r < s) return;
	updateLazy(node, s, e);
	if (l <= s && r >= e) {
		lazyTree[node] += l;
        ++lazyCnt[node];
        return;
	}
	int mid = (s + e) >> 1;
	setLazy(node * 2, l, r,  s, mid);
	setLazy(node * 2 + 1, l, r, mid + 1, e);
}

ll query(int node, int x, int s, int e) {
	if (s > x || e < x) return 0;
	updateLazy(node, s, e);
	if (s == e) return arr[x];
	int mid = (s + e) >> 1;
	ll lret = query(node * 2, x, s, mid);
	if (lret) return lret;
	return query(node * 2 + 1, x, mid + 1, e);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	cin >> Q;
	int q, l, r;
	while (Q--) {
		cin >> q;
		if (q == 1) {
			cin >> l >> r;
			setLazy(1, l, r, 1, n);
		}
		else {
			cin >> l;
			cout << query(1, l, 1, n) << "\n";
		}
	}
}