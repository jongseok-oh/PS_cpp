#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
vector<pair<int, int>> dots;

int calcDiff(const pair<int, int>& a, const pair<int, int>& b) {
	auto [lx, ly] = a;
	auto [rx, ry] = b;
	int xDiff = lx - rx, yDiff = ly - ry;
	return xDiff * xDiff + yDiff * yDiff;
}

int getMinDiff(int f, int to) {
	int _min = 1e9;
	for (int i = f; i < to; ++i) for (int j = i + 1; j <= to; ++j) {
		_min = min(_min, calcDiff(dots[i], dots[j]));
	}
	return _min;
}


int solve(int low, int high) {
	if (high - low <= 2) {
		return getMinDiff(low, high);
	}

	int mid = (low + high) >> 1;
	int ret = min(solve(low, mid), solve(mid, high));
	int midX = dots[mid].first;

	vector<pair<int, int>> candi;
	for (int i = low; i <= high; ++i) {
		int xDiff = midX - dots[i].first;
		if (xDiff * xDiff < ret)
			candi.push_back(dots[i]);
	}
	sort(candi.begin(), candi.end(), [&](auto& a, auto& b) {
		return a.second < b.second;
	});

	for (int i = 0, n = candi.size(); i < n; ++i) {
		auto [lx, ly] = candi[i];
		for (int j = i + 1; j < n; ++j) {
			auto [rx, ry] = candi[j];
			int yDiff = ly - ry;
			if (yDiff * yDiff >= ret) break;
			ret = min(ret, calcDiff({ lx,ly }, { rx,ry }));
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	dots.resize(n);
	for (auto& [x, y] : dots) cin >> x >> y;
	sort(dots.begin(), dots.end());

	cout << solve(0, n - 1);
}