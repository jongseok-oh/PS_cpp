#include <iostream>

using namespace std;

typedef long long ll;

int cntTree[850000];
ll sumTree[850000];


void updateCnt(int node, int left, int right, int tar) {
	if (right < tar || left > tar) return;
	if (right == left) {
		cntTree[node]++;
		return;
	}

	int mid = (left + right) >> 1;
	updateCnt(node * 2, left, mid, tar);
	updateCnt(node * 2 + 1, mid + 1, right, tar);

	cntTree[node] = cntTree[node * 2] + cntTree[node * 2 + 1];
}

// start, end = target
int getCnt(int node, int left, int right, int start, int end) {
	if (right < start || left > end) return 0;
	if (left >= start && right <= end) return cntTree[node];
	int mid = (left + right) >> 1;
	return getCnt(node * 2, left, mid, start, end) + getCnt(node * 2 + 1, mid + 1, right, start, end);
}

void updateSum(int node, int left, int right, int tar) {
	if (right < tar || left > tar) return;
	if (right == left) {
		sumTree[node] += tar;
		return;
	}

	int mid = (left + right) >> 1;
	updateSum(node * 2, left, mid, tar);
	updateSum(node * 2 + 1, mid + 1, right, tar);

	sumTree[node] = sumTree[node * 2] + sumTree[node * 2 + 1];
}

// start, end = target
ll getSum(int node, int left, int right, int start, int end) {
	if (right < start || left > end) return 0;
	if (left >= start && right <= end) return sumTree[node];
	int mid = (left + right) >> 1;
	return getSum(node * 2, left, mid, start, end) + getSum(node * 2 + 1, mid + 1, right, start, end);
}

ll MOD = 1000000007;
int MAX = 200000;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	ll ans = 1;
	for (int i = 0; i < n; i++) {
		int coord; cin >> coord;

		if (i) {
			int leftCnt = getCnt(1, 0, MAX, 0, coord);
			int rightCnt = getCnt(1, 0, MAX, coord, MAX);

			ll leftSum = getSum(1, 0, MAX, 0, coord);
			ll rightSum = getSum(1, 0, MAX, coord, MAX);

			ll cost = ((ll)leftCnt * coord -leftSum  + rightSum - (ll)rightCnt * coord) % MOD;
			ans = ans * cost % MOD;
		}

		if (!ans) break;

		updateCnt(1, 0, MAX, coord);
		updateSum(1, 0, MAX, coord);
	}
	cout << ans;
}