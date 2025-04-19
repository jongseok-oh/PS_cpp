#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

struct LIne {
	int a, b, cost;
}lines[100000];

int parent[1001];

int getP(int t) {
	if (!parent[t]) return t;
	return parent[t] = getP(parent[t]);
}

bool merge(int a, int b) {
	int aP = getP(a), bP = getP(b);

	if (aP == bP) return false;

	parent[bP] = aP;

	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> lines[i].a >> lines[i].b >> lines[i].cost;

	sort(lines, lines + m, [](const LIne& a, const LIne& b) {
		return a.cost < b.cost;
	});

	int sum = 0, cnt = 0;

	for(int i = 0; i<m; i++)
		if (merge(lines[i].a, lines[i].b)) {
			sum += lines[i].cost;
			if (++cnt == n - 1) break;
		}

	cout << sum;
}