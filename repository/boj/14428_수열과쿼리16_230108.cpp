#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n,m;

int arr[100001];
pii tree[400000];

pii init(int node, int left, int right) {
	if (left == right) return tree[node] = {arr[left], left};
	int mid = (left + right) >> 1;
	return tree[node] = min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
}

int q, a, b;
void Update(int node, int left, int right) {
	if (right < a || left >a) return;
	if (left == a && right == a) {
		tree[node].first = b; return;
	}
	int mid = (left + right) >> 1;
	Update(node * 2, left, mid);
	Update(node * 2 + 1, mid + 1, right);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

pii getMin(int node, int left, int right) {
	if (right < a || left >b) return { 0x7fffffff,0x7fffffff };
	if (a <= left && b >= right) return tree[node];
	int mid = (left + right) >> 1;
	return min(getMin(node * 2, left, mid), getMin(node * 2 + 1, mid + 1, right));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	cin >> m;
	while (m--) {
		cin >> q >> a >> b;
		if (q == 1) {
			Update(1, 1, n);
		}
		else {
			cout << getMin(1, 1, n).second<<"\n";
		}
	}
}