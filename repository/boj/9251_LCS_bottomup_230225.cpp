#include <iostream>
#include <algorithm>

using namespace std;

string a, b;

// dp[i][j]
// 길이가 각각 i, j인 문자열의 LCS 길이
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	int n = a.size(), m = b.size();

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int& ret = dp[i + 1][j + 1];
		if (a[i] == b[j]) ret = dp[i][j] + 1;
		else ret = max(dp[i + 1][j], dp[i][j + 1]);
	}
	cout << dp[n][m];
}