#include <iostream>
#include <set>

using namespace std;

typedef pair<int, int> pii;

int n;

pii lines[3000][2];

int parent[3000];

int ccw(pii& a, pii& b, pii& c) {
	int ret = (b.first - a.first) * (c.second - a.second)
		- (c.first - a.first) * (b.second - a.second);

	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	return ret;
}

bool isCrossed(int lineA, int lineB) {
	int A2B = ccw(lines[lineA][0], lines[lineA][1], lines[lineB][0])
		* ccw(lines[lineA][0], lines[lineA][1], lines[lineB][1]);
	int B2A = ccw(lines[lineB][0], lines[lineB][1], lines[lineA][0])
		* ccw(lines[lineB][0], lines[lineB][1], lines[lineA][1]);

	if (!A2B && !B2A) {
		if (lines[lineA][0] > lines[lineA][1]) swap(lines[lineA][0], lines[lineA][1]);
		if (lines[lineB][0] > lines[lineB][1]) swap(lines[lineB][0], lines[lineB][1]);
		return lines[lineB][1] >= lines[lineA][0] && lines[lineB][0] <= lines[lineA][1];
	}
	else {
		if (A2B <= 0 && B2A <= 0) return true;
	}
	return false;
}

int getParent(int t) {
	if (parent[t] < 0) return t;
	return parent[t] = getParent(parent[t]);
}

void Union(int lineA, int lineB) {
	int ap = getParent(lineA);
	int bp = getParent(lineB);
	if (ap == bp) return;
	parent[ap] += parent[bp];
	parent[bp] = ap;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> lines[i][0].first >> lines[i][0].second >> lines[i][1].first >> lines[i][1].second;

	for (int i = 0; i < n; i++) parent[i] = -1;

	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		if (isCrossed(i, j)) {
			Union(i, j);
		}
	}
	set<int> parentSet;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tp = getParent(i);
		ans = max(ans, -parent[tp]);
		parentSet.insert(tp);
	}
	cout << parentSet.size() << "\n" << ans;
}