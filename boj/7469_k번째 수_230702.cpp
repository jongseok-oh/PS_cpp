#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> segTree[400000];

void insert(int node, int idx, int val, int left, int right) {
	if (left > idx || right < idx) return;

	segTree[node].push_back(val);

	if (left == right) return;

	int mid = (left + right) >> 1;
	insert(node * 2, idx, val, left, mid);
	insert(node * 2 + 1, idx, val, mid + 1, right);
}

int bns(int node, int val) {
	vector<int>& Node = segTree[node];

	// val 이하인 수의 개수
	int left = -1, right = Node.size();
	while (left + 1 < right)
	{
		int mid = (left + right) >> 1;
		if (Node[mid] > val) right = mid;
		else left = mid;
	}
	return left + 1;
}

int search(int node, int start, int end, int val, int left, int right) {
	if (start > right || end < left) return 0;
	if (start <= left && end >= right) return bns(node, val);
	
	int mid = (left + right) >> 1;

	return search(node * 2, start, end, val, left, mid) +
	search(node * 2 + 1, start, end, val, mid + 1, right);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m;
	int _max = -1e9 - 1, _min = 1e9 + 1;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		insert(1, i, num, 0, n - 1);
		_max = max(_max, num);
		_min = min(_min, num);
	}

	for (int i = 1; i < 4 * n; i++)
		sort(segTree[i].begin(), segTree[i].end());

	while (m--) {
		int i, j, k; cin >> i >> j >> k;
		--i; --j; k;
		int left = _min - 1, right = _max + 1;
		while (left + 1< right) {
			int mid = (left + right) >> 1;
			int calc = search(1, i, j, mid, 0, n - 1);

			if (calc >= k) right = mid;
			else left = mid;
		}
		cout << right << "\n";
	}
}