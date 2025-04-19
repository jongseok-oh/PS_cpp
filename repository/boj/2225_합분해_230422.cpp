#include <iostream>

using namespace std;

int n, k;

int MOD = 1e9;

int dp[201][201];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 0; i <= n; i++) dp[1][i] = 1;

	for (int cnt = 2; cnt <= k; cnt++) {
		for (int num = 0; num <= n; num++) {
			// dp[cnt][num]을 구하자
			for (int tnum = 0; tnum <= num; tnum++) {
				dp[cnt][num] += dp[cnt - 1][tnum];
				dp[cnt][num] %= MOD;
			}
		}
	}
	cout << dp[k][n];
}