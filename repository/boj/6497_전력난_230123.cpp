#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

struct road
{
	int i, j, cost;
}roads [200000];

bool cmp(road& a, road& b) {
	return a.cost < b.cost;
}

int p[200000];

int getP(int t) {
	if (t == p[t]) return t;
	return p[t] = getP(p[t]);
}

bool Union(int a, int b) {
	int aP = getP(a);
	int bP = getP(b);

	if (aP == bP) return false;
	p[aP] = bP;
	return true;
}

int main() {
	while (true) {
		cin >> m >> n;
		if (!n && !m) break;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> roads[i].i >> roads[i].j >> roads[i].cost;
			sum += roads[i].cost;
		}
		sort(roads, roads + n,cmp);
		
		for (int i = 0; i < m; i++) p[i] = i;

		int tcost = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (Union(roads[i].i, roads[i].j)) {
				tcost += roads[i].cost;
				cnt++;
			}
			if (cnt == m - 1) break;
		}
		cout << sum - tcost<<"\n";
	}
}