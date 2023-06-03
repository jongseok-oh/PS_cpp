#include <iostream>

using namespace std;

int n;
int query[100000];

int power[5][5] = {
	{9,2,2,2,2},
	{9,1,3,4,3},
	{9,3,1,3,4},
	{9,4,3,1,3},
	{9,3,4,3,1}
};

int dp[100001][5][5];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true) {
		int num; cin >> num;
		if (!num) break;
		query[n++] = num;
	}

	for (int j = 0; j < 5; j++) for (int k = 0; k < 5; k++)
		dp[0][j][k] = 1e9;

	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++) {
		int q = query[i];

		for (int j = 0; j < 5; j++) for (int k = 0; k < 5; k++)
			dp[i + 1][j][k] = 1e9;

		// 현재 dp[i+1]
		// 과거 값 dp[i]
		for (int left = 0; left < 5; left++) for (int right = 0; right < 5; right++) {
			if (dp[i][left][right] != 1e9) {
				// 왼발 움직이기
				if (q != right) {
					dp[i + 1][q][right] = min(dp[i + 1][q][right], dp[i][left][right] + power[left][q]);
				}
				// 오른발 움직이기
				if (q != left) {
					dp[i + 1][left][q] = min(dp[i + 1][left][q], dp[i][left][right] + power[right][q]);
				}
			}
		}
	}

	int ans = 1e9;

	for (int left = 0; left < 5; left++) for (int right = 0; right < 5; right++)
		ans = min(dp[n][left][right], ans);

	cout << ans;
}