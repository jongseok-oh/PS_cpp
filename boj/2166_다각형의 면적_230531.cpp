#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int dots[10000][2];
int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> dots[i][0] >> dots[i][1];

	ll ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ans += 1LL * (dots[i][0] - dots[0][0]) * (dots[i + 1][1] - dots[0][1])
			- 1LL * (dots[i][1] - dots[0][1]) * (dots[i + 1][0] - dots[0][0]);
	}
	cout << fixed;
	cout.precision(1);
	cout <<(double)(ans < 0 ? -ans : ans)/2;
}