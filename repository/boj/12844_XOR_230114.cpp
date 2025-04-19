#include <iostream>

using namespace std;

int n,m;
int arr[500000];

int tree[4000000];
int lazy[4000000];

int query, i, j, k;

void updateLazy(int node, int left, int right) {
	if (lazy[node]) {
		tree[node] ^= (right - left + 1) & 1 ? lazy[node]:0;
		if (left != right) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

int init(int node, int left, int right) {
	if (left == right) return tree[node] = arr[left];
	int mid = (left + right) >> 1;
	return tree[node] = init(node * 2, left, mid) ^ init(node * 2 + 1, mid + 1, right);
}

void updateXOR(int node, int left, int right) {
	updateLazy(node, left, right);
	if (left > j || right < i) return;
	if (left >= i && right <= j) {
		tree[node] ^= (right - left + 1)&1?k:0;
		if (left != right) {
			lazy[node * 2] ^= k;
			lazy[node * 2 + 1] ^= k;
		}
		return;
	}
	int mid = (left + right) >> 1;
	updateXOR(node * 2, left, mid);
	updateXOR(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int getXOR(int node, int left, int right) {
	updateLazy(node, left, right);
	if (left > j || right < i) return 0;
	if (left >= i && right <= j) return tree[node];
	int mid = (left + right) >> 1;
	return getXOR(node * 2, left, mid) ^ getXOR(node * 2 + 1, mid + 1, right);
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(1, 0, n - 1);
	cin >> m;
	while (m--){
		cin >> query >> i >> j;
		if (query == 1) {
			cin >> k;
			updateXOR(1, 0, n - 1);
		}
		else {
			cout << getXOR(1, 0, n - 1) << "\n";
		}
	}
}