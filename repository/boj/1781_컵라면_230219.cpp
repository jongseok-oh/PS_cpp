#include <iostream>
#include <algorithm>

using namespace std;

int n;
struct noodle
{
	int deadLIne, cnt;
}noodles[200000];

int parent[200001];

bool cmp(noodle& a, noodle& b) {
	return a.cnt > b.cnt;
}

int getP(int t) {
	if (parent[t] == t) return t;
	return parent[t] = getP(parent[t]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> noodles[i].deadLIne >> noodles[i].cnt;

	sort(noodles, noodles + n, cmp);
	for (int i = 1; i <= n; i++) parent[i] = i;

	int ans = 0; 
	for (int i = 0; i < n; i++) {
		int p = getP(noodles[i].deadLIne);
		if (p) {
			ans += noodles[i].cnt;
			parent[p] = p - 1;
		}
	}
	cout << ans;
}
