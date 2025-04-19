#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		long long n; cin >> n;
		
		int visit = 0;

		long long tnum = n;
		while (true) {
			long long ttnum = tnum;
			while (ttnum) {
				visit |= (1 << (ttnum % 10));
				ttnum /= 10;
			}
			if (visit == ((1 << 10) - 1)) break;
			tnum += n;
		}
		cout << "#" << t << " " << tnum << "\n";
	}
	return 0;
}
