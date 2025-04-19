#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a, b;
int k;

ll __square(ll num, int tk) {
	if (tk == 1) return num;

	ll half = __square(num, tk / 2);
	
	ll ret = half * half % (a + b);
	if (tk & 1) ret = ret * num % (a + b);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		 cin >> a >> b >> k;
		 cout << "#" << tt << " " << min(a*__square(2, k) % (a+b), b*__square(2, k) %(a+b)) << "\n";
	}
}