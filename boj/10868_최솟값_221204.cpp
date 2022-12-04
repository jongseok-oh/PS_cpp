#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int arr[100001];
int tree[400001];

int init(int node, int left, int right) {

	if (left == right) return tree[node] = arr[left];

	int mid = (left + right) >> 1;

	return tree[node] = min(init(node * 2, left, mid), init(node * 2 + 1, mid + 1, right));
}

int a, b;

int getMin(int left, int right, int node) {
	if (left > b || right < a) return 1e9;

	if (left >= a && right <= b) return tree[node];

	int mid = (left + right) >> 1;

	return min(getMin(left, mid, node * 2), getMin(mid + 1, right, node * 2 + 1));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m;
	
	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, 1, n);

	while (m--) {
		cin >> a >> b;
		cout << getMin(1, n, 1) << "\n";
	}
}