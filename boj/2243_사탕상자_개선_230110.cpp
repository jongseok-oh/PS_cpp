#include <iostream>

using namespace std;

int n;

int a, b, c;

int tree[4000000];

void insertCandy(int node, int left, int right) {
	if (left > b || right < b) return;
	if (left == b && right == b) {
		tree[node] += c; return;
	}
	int mid = (left + right) >> 1;
	insertCandy(node * 2, left, mid);
	insertCandy(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int x, int left, int right) {
	if (left == right) return left;
	int mid = (left + right) >> 1;
	if (tree[node * 2] >= x) {
		return Query(node * 2, x, left, mid);
	}else return Query(node * 2 + 1, x - tree[node * 2], mid+1, right);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a == 1) {
			int ans = Query(1, b, 1,1000000);
			cout << ans << "\n";
			b = ans; c = -1;
			insertCandy(1, 1, 1000000);
		}
		else {
			cin >> c;
			insertCandy(1, 1, 1000000);
		}
	}
}