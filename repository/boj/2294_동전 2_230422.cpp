#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

int coins[100];

int dp[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> coins[i];

	for (int i = 1; i <= k; i++) dp[i] = 1e9;

	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);

	cout << (dp[k] == 1e9 ? -1 : dp[k]);
}