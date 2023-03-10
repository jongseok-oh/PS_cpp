#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct dot {
	double y, x;
}dots[101];

struct line
{
	int from, to;
	double len;
};

int parent[101];

int getP(int t) {
	if (!parent[t]) return t;
	return parent[t] = getP(parent[t]);
}

bool merge(int a, int b) {
	int ap = getP(a),
		bp = getP(b);

	if (ap == bp) return false;

	parent[ap] = bp;
	return true;
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> dots[i].y >> dots[i].x;

	vector<line> lines;

	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		double ydiff = dots[i].y - dots[j].y,
			xdiff = dots[i].x - dots[j].x;

		double line = sqrt(ydiff * ydiff + xdiff * xdiff);

		lines.push_back({i,j,line});
	}

	sort(lines.begin(), lines.end(), [](line& a, line& b){return a.len < b.len;});

	int cnt = 0;
	double ans = 0;

	for (auto it = lines.begin(); it != lines.end(); it++) {
		int a = it->from,
			b = it->to;

		if (merge(a, b)) {
			cnt++;
			ans += it->len;
		}
		if (cnt == n - 1) break;
	}
	cout << ans;
}