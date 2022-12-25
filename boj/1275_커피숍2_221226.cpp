#include <iostream>

using namespace std;

typedef long long ll;

int n, q, x,y,a,b;

int arr[100000];
ll tree[400000];

ll init(int node, int left, int right) {
	if (left == right) return tree[node] = arr[left];

	int mid = (left + right) >> 1;
	return tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
}

ll getSum(int node, int left, int right) {
	if (right < x || left > y) return 0;
	if (left >= x && right <= y) return tree[node];
	
	int mid = (left + right) >> 1;
	return getSum(node * 2, left, mid) + getSum(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right) {
	if (right < a || left > a) return;
	if (left == a && right == a) {
		tree[node] = b; return;
	}
	int mid = (left + right) >> 1;
	update(node * 2, left, mid);
	update(node * 2 + 1, mid+ 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>q;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(1, 0, n - 1);

	while (q--) {
		cin >> x >> y >> a >> b;
		x--; y--; a--;
		if (x > y) {
			int temp = y;
			y = x;
			x = temp;
		}
		cout << getSum(1, 0, n - 1) << "\n";
		update(1, 0, n - 1);
	}
}