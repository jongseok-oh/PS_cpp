#include <iostream>

using namespace std;

typedef long long ll;

int n, m, k;

ll arr[1000001];
ll tree[4000001];

ll init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) >> 1;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

ll getSum(int start,int end, int node,int left, int right) {
	if (left > end || right < start) return 0;
	
	if (left <= start && right >= end) return tree[node];

	int mid = (start+ end) >> 1;
	return getSum(start, mid, node * 2, left, right) + getSum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx,ll diff) {
	if (idx<start || idx >end) return;
	
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) >> 1;
	update(start, mid, node * 2, idx, diff);
	update(mid+1, end, node * 2 + 1, idx, diff);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	
	int a, b;
	for (int i = 0; i < m + k; i++) {
		cin >> a>>b;
		if (a == 1) {
			ll c; cin >> c;
			update(1, n, 1, b, c - arr[b]);
			arr[b] = c;
		}
		else {
			int c; cin >> c;
			cout << getSum(1, n, 1, b, c) << "\n";
		}
	}

}