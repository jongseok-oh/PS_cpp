#include <iostream>

using namespace std;

int gcd(int m, int n) {
	if (n == 0) return m;
	return gcd(n, m % n);
}

int solve(int m, int n, int x, int y) {
	int end = m*n/gcd(m, n);

	int start = x;

	if (x == m) x = 0;
	if (y == n) y = 0;

	for (int i = start; i <= end; i += m)
		if (i % n == y) return i;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;

	while (T--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		
		cout << solve(m, n, x, y) << "\n";
	}
}