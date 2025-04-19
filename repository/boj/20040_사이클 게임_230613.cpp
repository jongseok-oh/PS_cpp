#include <iostream>
#include <cstring>

using namespace std;

int n, m;

int parent[500000];

int getP(int t) {
	if (parent[t] == -1) return t;
	return parent[t] = getP(parent[t]);
}

bool merge(int a, int b) {
	int aP = getP(a);
	int bP = getP(b);

	if (aP == bP) return false;

	parent[bP] = aP;

	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	memset(parent, -1, 4 * n);

	int ans = 1;
	while (m--) {
		int a, b; cin >> a >> b;
		if (!merge(a, b)) {
			cout << ans; return 0;
		}
		ans++;
	}
	cout << 0;
}