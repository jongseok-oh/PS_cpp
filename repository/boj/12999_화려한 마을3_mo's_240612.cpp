#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Query { int x, y, idx; };

int n,q;
vector<Query> queries;
vector<int> paint, ret;

const int diff = 1e5;
int cnt[diff * 2 + 1];
int cntCnt[diff + 1];

int ans = 0;
void push(int bright) {
	--cntCnt[cnt[bright]];
	ans = max(ans, ++cnt[bright]);
	++cntCnt[cnt[bright]];
}

void pop(int bright) {
	--cntCnt[cnt[bright]];
	if (cnt[bright] == ans && cntCnt[cnt[bright]] == 0) --ans;
	cntCnt[--cnt[bright]]++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>q;
	queries.resize(q); ret.resize(q); paint.resize(n);

	for (auto& bright : paint) {
		cin >> bright; bright += diff;
	}

	int tIdx = 0;
	for (auto& [x, y, idx] : queries) {
		cin >> x >> y; idx = tIdx++;
		--x; --y;
	}

	int batch = sqrt(n);
	sort(queries.begin(), queries.end(), [&](Query& q1, Query q2) {
		int b1 = q1.x / batch, b2 = q2.x / batch;
		return b1 < b2 || (b1 == b2 && q1.y < q2.y);
	});
	auto [l, r, _] = queries[0];
	for (int i = l; i <= r; ++i) push(paint[i]);
	ret[_] = ans;

	for (int i = 1; i < q; ++i) {
		auto [x, y, idx] = queries[i];
		while (l < x) pop(paint[l++]);
		while (l > x) push(paint[--l]);
		while (r < y) push(paint[++r]);
		while (r > y) pop(paint[r--]);
		ret[idx] = ans;
	}

	for (int count : ret) cout << count << "\n";
}