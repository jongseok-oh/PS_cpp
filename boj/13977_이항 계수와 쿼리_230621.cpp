#include <iostream>

using namespace std;

int facto[4000001];

int MOD = 1e9 + 7;
int n, k;

int _pow(int revfacto, int t) {
	if (t == 1) return revfacto;

	int half = _pow(revfacto, t / 2);
	int ret = 1LL * half * half % MOD;

	return t & 1 ? 1LL * ret * revfacto % MOD : ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	facto[0] = 1;
	facto[1] = 1;

	for (int i = 2; i < 4000001; i++) facto[i] = 1LL * facto[i - 1] * i % MOD;

	int m; cin >> m;
	while (m--) {
		cin >> n >> k;

		cout << (1LL * facto[n] * _pow(1LL * facto[n - k] * facto[k] % MOD, MOD - 2) % MOD) << "\n";
	}
}