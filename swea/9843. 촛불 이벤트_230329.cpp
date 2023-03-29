#include <iostream>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		long long n; cin >> n;

		long long sqr = sqrt(1 + 8 * n);
		long long ans = -1;
		if (sqr * sqr == (1 + 8*n) && (sqr&1)) ans = (-1 + sqr) / 2;

		cout << "#" << tt << " " << ans << "\n";
	}
}