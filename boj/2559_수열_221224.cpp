#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

int temper[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> temper[i];
	
	int ans = 0;
	for (int i = 0; i < k; i++) ans += temper[i];

	int sum = ans;
	for (int i = 1; i < n - k + 1; i++) {
		sum += -temper[i - 1] + temper[i + k - 1];
		ans = max(ans, sum);
	}
	cout << ans;
}