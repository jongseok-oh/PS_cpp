#include <iostream>

using namespace std;

typedef long long ll;

int n,m,k;

ll arr[1000000];
ll tree[4000001];
ll lazy[4000001];

ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) >> 1;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll a, b, c, d;

void updateLazy(int start, int end, int node) {
	if (lazy[node]) {
		tree[node] += lazy[node] * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

ll getSum(int start, int end, int node) {
	updateLazy(start, end, node);
	if (start > c || end < b) return 0;
	if (start >= b && end <= c) return tree[node];
	
	int mid = (start + end) >> 1;
	return getSum(start, mid, node * 2) + getSum(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node) {
	updateLazy(start, end, node);
	if (!((start <= b && end >= c)||(start <= c && start >= b) || (end >= b && end <= c))) return;
	if (start >= b && end <= c) {
		tree[node] += (end - start + 1) * d;
		if (start != end) {
			lazy[node * 2] += d;
			lazy[node * 2 + 1] += d;
		}
		return;
	}
	int mid = (start + end) >> 1;
	update(start, mid, node * 2);
	update(mid+1, end, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m>>k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(0, n - 1, 1);

	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		b--; c--;
		if (a == 1) {
			cin >> d;
			update(0, n - 1, 1);
		}
		else {
			cout<<getSum(0, n - 1, 1)<<"\n";
		}
	}
}