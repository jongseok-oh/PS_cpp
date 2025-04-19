#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int n;

vector<int> yIdxs;
vector<pair<int, int>> dots;

int getIdx(vector<int>& idx, int val) {
	return lower_bound(idx.begin(), idx.end(), val) - idx.begin();
}

ll tree[300000];
ll get(int node,int l, int r, int tar) {
	if (r <= tar) return tree[node];
	if (l > tar) return 0;
	int mid = (l + r) >> 1;
	return get(node * 2, l, mid, tar) + get(node * 2 + 1, mid + 1, r, tar);
}

void update(int node, int l, int r, int val) {
	if (l == r && l == val) {
		tree[node]++; return;
	}
	if (val > r || l > val) return;
	int mid = (l + r) >> 1;
	update(node * 2, l, mid, val);
	update(node * 2 + 1, mid + 1, r, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		dots.resize(n); yIdxs.clear();
		int x, y;
		for (auto& [x,y]:dots) {
			cin >> x >> y;
			yIdxs.push_back(y);
		}

		sort(yIdxs.begin(), yIdxs.end());
		yIdxs.erase(unique(yIdxs.begin(), yIdxs.end()), yIdxs.end());
		sort(dots.begin(), dots.end(), [&](auto& a, auto& b) {
			return a.first > b.first || (a.first == b.first && a.second < b.second);
		});

		ll ret = 0;
		memset(tree, 0, 8 * 4 * n);
		for (auto& [x, y] : dots) {
			int yIdx = getIdx(yIdxs, y);
			ret += get(1, 0, yIdxs.size() - 1, yIdx);
			update(1, 0, yIdxs.size() - 1, yIdx);
		}
		cout << ret << "\n";
	}
}
