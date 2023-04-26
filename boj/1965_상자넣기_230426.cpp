#include <iostream>
#include <algorithm>

using namespace std;

int n;

int box[1000];
int dp[1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> box[i];

	int ans = 1;

	for (int i = n - 1; i >= 0; i--) {
		dp[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (box[i] < box[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(dp[i], ans);
	}
	cout << ans;
}