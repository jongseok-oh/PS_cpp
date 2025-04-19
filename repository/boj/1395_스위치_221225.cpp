#include <iostream>

using namespace std;

int n, m, o,s,t;

int sum[400000];
bool lazy[400000];

void updateLazy(int node, int left, int right) {
	if (lazy[node]) {
		sum[node] = right - left + 1 - sum[node];

		if (right != left) {
			lazy[node * 2] ^= true;
			lazy[node * 2 + 1] ^= true;
		}
		lazy[node] = false;
	}
}

void toggle(int node, int left, int right) {
	updateLazy(node, left, right);
	if (right < s || left > t) return;
	if (left >= s && right <= t) {
		sum[node] = right - left + 1 - sum[node];
		if (right != left) {
			lazy[node * 2] ^= true;
			lazy[node * 2 + 1] ^= true;
		}
		return;
	}
	int mid = (left + right) >> 1;
	toggle(node * 2, left, mid);
	toggle(node * 2 + 1, mid + 1, right);
	sum[node] = sum[node * 2] + sum[node * 2 + 1];
}

int getSum(int node, int left, int right) {
	updateLazy(node, left, right);
	if (right < s || left > t) return 0;
	if (left >= s && right <= t) return sum[node];

	int mid = (left + right) >> 1;

	return getSum(node * 2, left, mid) + getSum(node * 2 + 1, mid + 1, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	while (m--) {
		cin >> o >> s >> t;
		s--; t--;
		if (!o) toggle(1, 0, n-1);
		else cout << getSum(1, 0, n-1)<<"\n";
	}
}