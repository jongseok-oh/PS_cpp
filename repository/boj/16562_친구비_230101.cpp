#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

int fmoney[10001];
int parent[10001];

int getP(int t) {
	if (!parent[t]) return t;
	return parent[t] = getP(parent[t]);
}

void Union(int v, int w) {
	int vp = getP(v);
	int wp = getP(w);

	if (vp == wp) return;

	parent[wp] = vp;
	fmoney[vp] = min(fmoney[vp], fmoney[wp]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> fmoney[i];

	int v, w;
	while (m--) {
		cin >> v >> w;
		Union(v, w);
	}

	int fmoneySum = 0;

	for (int i = 1; i <= n; i++) {
		int p = getP(i);
		if (fmoney[p] != -1) {
			fmoneySum += fmoney[p];
			fmoney[p] = -1;
		}
		if (fmoneySum > k) {
			cout << "Oh no"; return 0;
		}
	}
	cout << fmoneySum;
}