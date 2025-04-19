#include <iostream>
#include <vector>

using namespace std;

int n;
int mod = 1e9;

int dp[1 << 10][10][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i < 10; i++) dp[1 << i][i][1] = 1;

	vector<vector<int>> chk = { {1},{0,2},{1,3},{2,4},{3,5},{4,6},{5,7},{6,8},{7,9},{8}};

	for (int i = 2; i <= n; i++) {
		for (int num = 0; num < 10; num++) {
			for (int j = 0, len = 1 << 10; j < len; j++) {
				for (int endNum : chk[num]) {
					if (!dp[j][endNum][i-1]) continue;
					int tbit = j;
					tbit |= (1 << num);
					dp[tbit][num][i] += dp[j][endNum][i-1];
					dp[tbit][num][i] %= mod;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < 10; i++) {
		ans += dp[(1 << 10) - 1][i][n];
		ans %= mod;
	}

	cout << ans;
}