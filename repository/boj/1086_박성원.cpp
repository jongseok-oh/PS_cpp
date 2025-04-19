#include <iostream>
#include <string>

using namespace std;

int n,k;

string str[15];

int _mod[15], _size[15], _tenmod[15];

long long dp[1 << 15][100];

struct info
{
	int tmod;
	int visit;
};

int getmod(const string& t) {
	int mod = 0;
	for (int i = 0, len = t.size(); i < len; i++) {
		mod *= 10;
		mod += t[i] - '0';
		mod %= k;
	}
	return mod;
}

int tenmod(int num) {
	int mod = 1;
	while (num--) {
		mod *= 10;
		mod %= k;
	}
	return mod;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	cin >> k;

	for (int i = 0; i < n; i++) {
		_mod[i] = getmod(str[i]);
		_size[i] = str[i].size();
		_tenmod[i] = tenmod(_size[i]);
	}

	for (int i = 0; i < n; i++) dp[1 << i][_mod[i]]++;

	for (int i = 1, len = 1 << n; i < len; i++) {
		int t;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				t = i & (~(1 << j));
				for (int kk = 0; kk < k; kk++) {
					int nmod = (kk * _tenmod[j] + _mod[j]) % k;
					dp[i][nmod] += dp[t][kk];
				}
			}
		}
	}

	long long p = dp[(1 << n) - 1][0];

	long long q = 1;

	for (int i = 2; i <= n; i++) q *= i;

	long long _gcd = gcd(p, q);

	cout << (p / _gcd) << "/" << (q / _gcd);
}