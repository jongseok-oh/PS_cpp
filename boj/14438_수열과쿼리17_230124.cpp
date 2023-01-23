#include <iostream>
#include <algorithm>

using namespace std;

int n,m, query, i, v;

int arr[100001];
int tree[400000];

int init(int node, int left, int right) {
	if (left == right) return tree[node] = arr[left];
	int mid = (left + right) >> 1;
	return tree[node] = min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
}

int getMin(int node, int left, int right) {
	if (right < i || left >v) return 1e9;
	if (left >= i && right <= v) return tree[node];
	int mid = (left + right) >> 1;
	return min(getMin(node * 2, left, mid), getMin(node * 2 + 1, mid + 1, right));
}

void Update(int node, int left, int right) {
	if (right < i || left >i) return;
	if (left == right) {
		tree[node] = v; return;
	}
	int mid = (left + right) >> 1;
	Update(node * 2, left, mid);
	Update(node * 2 + 1, mid+1, right);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <=n; i++) cin>>arr[i];
	init(1, 1, n);

	cin >> m;
	while (m--) {
		cin >> query >> i >> v;
		if (query == 1) {
			Update(1, 1, n);
		}
		else {
			cout<<getMin(1, 1, n)<<"\n";
		}
	}
}