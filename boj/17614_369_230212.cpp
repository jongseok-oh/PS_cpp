#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int ans = 0;
	for (int i = 3; i <= n; i++) {
		int t = i;
		while (t) {
			int rem = t % 10;
			if (rem == 3 || rem == 6 || rem == 9) ans++;
			t /= 10;
		}
	}
	cout << ans;
}
