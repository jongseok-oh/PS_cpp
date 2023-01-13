#include <iostream>

using namespace std;

typedef long long ll;

int n, m, a, i,j;

ll tree[4000000];

ll Sum(int node, int left, int right) {
	if (left > j || right < i) return 0;
	if (i <= left && j >= right) return tree[node];
	int mid = (left + right) >> 1;
	return Sum(node * 2, left, mid) + Sum(node * 2 + 1, mid + 1, right);
}

void Modify(int node, int left, int right) {
	if (left > i || right < i) return;
	if (left == i && right == i) {
		tree[node] = j; return;
	}
	int mid = (left + right) >> 1;
	Modify(node * 2, left, mid);
	Modify(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;;
	
	while (m--) {
		cin >> a >> i >> j;
		i--;
		if (!a) {
			j--;
			if (i > j) swap(i, j);
			cout << Sum(1, 0, n - 1) << "\n";
		}
		else Modify(1, 0, n - 1);
	}
}