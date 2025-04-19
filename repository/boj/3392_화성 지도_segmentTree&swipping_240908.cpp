#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Line {
	int x, y1, y2, val;
};
const int _MAX = 30000;
int n, tree[_MAX * 8], cnt[_MAX * 8];
void _update(int node, int l, int r, int s, int e, int val) {
	if (l > e || r < s) return;
	if (s <= l && r <= e) {
		cnt[node] += val;
	}
	else {
		int mid = (l + r) >> 1;
		_update(node * 2, l, mid, s, e, val);
		_update(node * 2 + 1, mid + 1, r, s, e, val);
	}
	if (cnt[node] > 0) tree[node] = r - l + 1;
	else {
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<Line> lines(n * 2);
	int x1, y1, x2, y2;
	for (int i = 0; i < n * 2; i += 2) {
		cin >> x1 >> y1 >> x2 >> y2;
		lines[i] = { x1,y1,y2, 1 };
		lines[i + 1] = { x2,y1,y2, -1 };
	}
	sort(lines.begin(), lines.end(), [&](Line& a, Line& b) {
		return a.x < b.x;
	});

	int lastX = -1;
	ll ret = 0;
	for (auto&[x, y1, y2, val] : lines) {
		if (lastX != -1) {
			ret += (x - lastX) * tree[1];
		}
		_update(1, 0, _MAX, y1, y2 - 1, val);
		lastX = x;
	}
	cout << ret;
}
