#include <iostream>

using namespace std;

typedef long long ll;

int n;

int order[1000001];

int tree[2000000];

int num;

// get prefix from num to n-1
int getCnt(int node, int left, int right) {
	if (right < order[num]) return 0;
	if (order[num] <= left && n - 1 >= right) return tree[node];
	int mid = (left + right) >> 1;
	return getCnt(node * 2, left, mid) + getCnt(node * 2 + 1, mid + 1, right);
}

void Update(int node, int left, int right) {
	if (left > order[num] || right < order[num]) return;
	if (left == order[num] && right == order[num]) {
		tree[node] = 1; return;
	}
	int mid = (left + right) >> 1;
	Update(node * 2, left, mid);
	Update(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		order[num] = i;
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		ans += getCnt(1, 0, n - 1);
		Update(1, 0, n - 1);
	}
	cout << ans;
}