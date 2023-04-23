#include <iostream>

using namespace std;

int n;

int dp[100000][3];

int MOD = 9901;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	dp[0][0] = 1, dp[0][1] = 1, dp[0][2] = 1;

	for (int i = 1; i < n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])%MOD;
	}

	cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2])%MOD;
}