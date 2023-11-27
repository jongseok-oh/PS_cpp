#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

const int MOD = 1e9 + 7;

int n;
int sc[300000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; ++i) cin >> sc[i];
	sort(sc, sc + n);

	ll ret = 0, prevSum = 0, _pow = 1;

	for (int i = 1; i < n; ++i) {
		prevSum = (prevSum * 2 + sc[i - 1]) % MOD;
		_pow = _pow * 2 % MOD;

		ll calc = (_pow - 1) * sc[i] - prevSum;
		if (calc < 0) calc += MOD;
		ret = (calc + ret) % MOD;
	}

	cout << ret;
}