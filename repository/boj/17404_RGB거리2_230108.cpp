#include <iostream>

using namespace std;

int n;
int home[3][1000];

int dp[3][1000][3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> home[0][i] >> home[1][i] >> home[2][i];

	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			if (j == k) dp[j][0][k] = home[j][0];
			else dp[j][0][k] = 1e9;
		}
		for (int i = 1; i < n; i++) {
			for (int kk = 0; kk < 3; kk++)
			{
				dp[j][i][kk] = 1e9;
				for (int rgb = 0; rgb < 3; rgb++)
					if (kk != rgb)
						dp[j][i][kk] = min(dp[j][i - 1][rgb] + home[kk][i], dp[j][i][kk]);
			}
		}
	}

	int ans = 1e9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (j != i) ans = min(ans, dp[i][n - 1][j]);
	}
	cout << ans;
}