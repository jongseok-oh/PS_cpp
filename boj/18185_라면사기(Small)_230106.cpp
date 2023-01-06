#include <iostream>
#include <algorithm>

using namespace std;

int n;
int ramen[10002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ramen[i];

	int idx = 0, ans = 0;

	while (true) {
		while (idx < n && !ramen[idx]) idx++;
		if (idx == n) break;
		if (ramen[idx + 1] > ramen[idx + 2]) {
			int _min = min(ramen[idx], ramen[idx + 1] - ramen[idx + 2]);
			ans += 5 * _min;
			for (int i = 0; i < 2; i++) ramen[idx + i] -= _min;

			_min = min({ ramen[idx], ramen[idx + 1] , ramen[idx + 2] });
			ans += 7 * _min;
			for (int i = 0; i < 3; i++) ramen[idx + i] -= _min;
		}
		else {
			int _min = min({ ramen[idx], ramen[idx + 1] , ramen[idx + 2] });
			ans += 7 * _min;
			for (int i = 0; i < 3; i++) ramen[idx + i] -= _min;
		}
		ans += ramen[idx] * 3;
		ramen[idx] = 0;
	}
	cout << ans;
}