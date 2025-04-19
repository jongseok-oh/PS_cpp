#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
double xSum, ySum, ans;

double dots[20][2];

void solve(int cnt, int idx) {
	if (!cnt) {
		ans = min(ans, sqrt(xSum * xSum + ySum * ySum));
		return;
	}

	for (int i = idx; i < n; i++) {
		xSum -= dots[i][0] * 2, ySum -= dots[i][1] * 2;
		solve(cnt - 1, i + 1);
		xSum += dots[i][0] * 2, ySum += dots[i][1] * 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed; cout.precision(7);

	int T; cin >> T;
	while (T--) {
		cin >> n;

		xSum = 0, ySum = 0, ans = 1e9;
		for (int i = 0; i < n; i++) {
			cin >> dots[i][0] >> dots[i][1];
			xSum += dots[i][0], ySum += dots[i][1];
		}

		solve(n/2, 0);
		cout << ans << "\n";
	}
}