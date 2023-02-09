#include <iostream>

using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (cin>>n) {
		cin >> k;
		int ans = 0, stamp = 0;
		while (n) {
			ans += n;
			stamp += n;
			n = stamp / k;
			stamp %= k;
		}
		cout << ans << "\n";
	}
}
