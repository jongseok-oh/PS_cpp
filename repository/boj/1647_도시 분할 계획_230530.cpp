#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

struct Road{
	int a, b, cost;
}roads[1000000];

int parent[100001];

int getP(int t) {
	if (!parent[t]) return t;
	return parent[t] = getP(parent[t]);
}

bool merge(int a, int b) {
	int aP = getP(a);
	int bP = getP(b);

	if (aP == bP) return false;

	parent[aP] = bP;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> roads[i].a >> roads[i].b >> roads[i].cost;

	sort(roads, roads + m, [](const Road& a, const Road& b)
		{return a.cost < b.cost;}
	);

	int con = 0, ans = 0;
	
	for (int i = 0; i < m; i++) {
		if (merge(roads[i].a, roads[i].b)) {
			ans += roads[i].cost;
			con++;
			if (con == n - 2) break;
		}
	}
	cout << ans;
}