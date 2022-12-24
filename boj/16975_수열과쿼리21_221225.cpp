#include <iostream>

using namespace std;

typedef long long ll;

int n,m, i, j, k;
int arr[100000];
ll tree[400000];
ll lazy[400000];

ll init(int node, int left, int right) {
	if (left == right) {return tree[node] = arr[left];}
	int mid = (left + right) >> 1;
	return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}

void updateLazy(int node, int left, int right) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node] * (right - left + 1);
		if (left != right) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int left, int right) {
	updateLazy(node, left, right);
	if (right < i || left > j) return;
	if (left >= i && right <= j) {
		tree[node] += 1LL * (right - left + 1) * k;
		if (left != right) {
			lazy[node * 2] += k;
			lazy[node * 2 + 1] += k;
		}
		return;
	}
	int mid = (left + right) >> 1;
	update(node * 2, left, mid);
	update(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getLeef(int node, int left, int right) {
	updateLazy(node, left, right);
	if (right < i || left > i) return 0;
	if (right == i && left == i) return tree[node];
	int mid = (left + right) >> 1;
	return getLeef(node * 2, left, mid) + getLeef(node * 2 + 1, mid + 1, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(1, 0, n - 1);
	cin >> m;

	int query;
	while (m--) {
		cin >> query >> i;
		i--;
		if (query == 1) {
			cin >> j >> k;
			j--;
			update(1, 0, n - 1);
		}
		else {
			cout<<getLeef(1, 0, n - 1)<<"\n";
		}
	}
}