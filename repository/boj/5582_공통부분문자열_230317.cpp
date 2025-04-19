#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string a, b;

int dp[4001][4001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	
	int ans = 0;

	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = b.size() - 1; j >= 0; j--) {
			if (a[i] == b[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}