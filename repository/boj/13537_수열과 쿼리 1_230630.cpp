#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

vector<int> segTree[400000];

void update(int node, int index,int left, int right, int val) {
	if (left > index || right < index) return;
	segTree[node].push_back(val);

	if (left == right) return;
	
	int mid = (left + right) >> 1;
	update(node * 2, index, left, mid, val);
	update(node * 2 + 1, index, mid + 1, right, val);
}

int getCnt(int node, int tar) {
	vector<int>& subtree = segTree[node];

	int left = -1, right = subtree.size();

	while (left + 1< right)
	{
		int mid = (left + right) >> 1;
		if (subtree[mid] > tar) right = mid;
		else left = mid;
	}

	return subtree.size() - right;
}

int search(int node, int s, int e, int val, int left, int right) {
	if (s > right || e < left) return 0;
	if (s <= left && e >= right) return getCnt(node, val);
	int mid = (left + right) >> 1;
	return search(node * 2, s, e, val, left, mid) + search(node * 2 + 1, s, e, val, mid + 1, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		update(1, i, 0, n - 1, num);
	}

	for (int node = 1; node < 4 * n; node++)
		sort(segTree[node].begin(), segTree[node].end());

	cin >> m;
	while (m--) {
		int i, j, k; cin >> i >> j >> k;

		cout << search(1, --i, --j, k, 0, n - 1) << "\n";
	}
}