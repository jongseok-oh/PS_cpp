#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int a[20000];
int b[20000];

int bns(int tar) {
	int low = -1, high = m;

	while (low + 1 < high) {
		int mid = (low + high) >> 1;
		
		if (b[mid] >= tar) high = mid;
		else low = mid;
	}
	return high;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		sort(a, a + n);
		sort(b, b + m);

		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans += bns(a[i]);
		}
		cout << ans << "\n";
	}
}