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

int mid;

int getCandyCnt(int node, int left, int right) {
	if (left > mid) return 0;
	if (right <= mid) return tree[node];
	int mid = (left + right) >> 1;
	return getCandyCnt(node * 2, left, mid) + getCandyCnt(node * 2 + 1, mid + 1, right);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a == 1) {
			int low = 0, high = 1000000;
			while (low + 1 < high) {
				mid = (low + high) >> 1;
				if (getCandyCnt(1, 1, 1000000) >= b) high = mid;
				else low = mid;
			}
			cout << high << "\n";
			b = high; c = -1;
			insertCandy(1, 1, 1000000);
		}
		else {
			cin >> c;
			insertCandy(1, 1, 1000000);
		}
	}
}