#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	int ret = 0;
	vector<vector<int>> dp(n, vector<int>(m));
	string buffer;
	for (auto& row : dp) {
		cin >> buffer;
		for (int i = 0; i < m; ++i) {
			row[i] = buffer[i] - '0';
			if (row[i] == 1) ret = 1;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (dp[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
				ret = max(ret, dp[i][j]);
			}
		}
	}
	cout << ret * ret;
}