#include <iostream>
#include <math.h>

using namespace std;

int n;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int t = 316;

	for (int i = 1; i <= t; i++) dp[i*i] = 1;

	for (int i = 2; i <= n; i++) {
		if (dp[i] == 1) continue;

		for (int j = 1, len = sqrt(i); j <= len; j++) {
			if (!dp[i] || dp[i] > dp[j*j] + dp[i - j * j])
				dp[i] = dp[j*j] + dp[i - j * j];
		}
	}
	cout << dp[n];
}