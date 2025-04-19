#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

long long tree[8000];

struct line
{
	int a, b;
}lines[2000000];

bool cmp(line& a, line& b) {
	if (a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}

long long getSum(int node, int left, int right, int tar) {
	if (right < tar) return 0;
	if (left >= tar && right <= n + 1) return tree[node];
	int mid = (left + right) >> 1;
	return getSum(node * 2, left, mid, tar) + getSum(node * 2 + 1, mid + 1, right, tar);
}

void Update(int node, int left, int right, int tar) {
	if (left > tar || right < tar) return;
	if (right == left) {
		tree[node]++; return;
	}
	int mid = (left + right) >> 1;
	Update(node * 2, left, mid, tar);
	Update(node * 2 + 1, mid+1, right, tar);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> lines[i].a >> lines[i].b;

	sort(lines, lines + m, cmp);

	long long ans = 0;
	for (int i = 0; i < m; i++) {
		ans += getSum(1, 1, n + 1, lines[i].b + 1);
		Update(1, 1, n + 1, lines[i].b);
	}
	cout << ans;
}
