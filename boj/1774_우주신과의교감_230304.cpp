#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>

using namespace std;

struct loc{
	double y, x;
}locs[1000];

int parent[1000];

int getP(int t) {
	if (parent[t] == -1) return t;
	return parent[t] = getP(parent[t]);
}

bool merge(int a, int b) {
	int ap = getP(a);
	int bp = getP(b);

	if (ap == bp) return false;

	parent[bp] = ap;
	return true;
}

int lineCnt = 0;

struct line {
	int node1, node2;
	double dist;
}lines[1000000];

bool cmp(line& a, line& b) {
	return a.dist < b.dist;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> locs[i].y >> locs[i].x;

	memset(parent, -1, sizeof(parent));
	
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		if (merge(a, b)) cnt++;
	}
	cout << fixed; cout.precision(2);
	if (cnt == n - 1) { cout << 0; return 0; }


	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		double ydiff = locs[i].y - locs[j].y,
			xdiff = locs[i].x - locs[j].x;
		lines[lineCnt++] = {
			i,j, sqrt(ydiff * ydiff + xdiff * xdiff)
		};
	}
	sort(lines, lines + lineCnt, cmp);

	double ans = 0;

	for (int i = 0; i < lineCnt; i++) {
		if (merge(lines[i].node1, lines[i].node2)) {
			ans += lines[i].dist;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << ans;
}
