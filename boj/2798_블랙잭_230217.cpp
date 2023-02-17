#include <iostream>

using namespace std;

int n, m;

int card[100];

int ans = -1;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> card[i];

	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) {
		int sum = card[i] + card[j] + card[k];
		if (sum <= m && sum > ans) ans = sum;
	}
	cout << ans;
}
