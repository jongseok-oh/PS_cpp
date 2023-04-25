#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n,m;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>m;

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		string line; cin >> line;
		for (int j = 1; j <= m; j++) {
			
			int& t = dp[i][j];

			if (line[j-1] == '1') {
				int _min = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] });
				t = _min + 1;
				ans = max(ans, t);
			}
		}
	}
	cout << ans*ans;
}