#include <iostream>
#include <cstring>

using namespace std;

string a, b;
int n, m;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> a >> b;
		n = a.size(), m = b.size();

		memset(dp, 0, sizeof(dp));

		for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) {
			if (a[i] == b[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
			else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		}
		cout << "#" << tt <<" "<<dp[0][0]<< "\n";
	}
}