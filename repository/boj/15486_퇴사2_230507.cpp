#include <iostream>
#include <algorithm>

using namespace std;

int n;

int t[1500001], p[1500001];
int dp[1500001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
	
	for (int i = 0; i <= n; i++) {
		if (i) {
			dp[i] = max(dp[i], dp[i - 1]);
		}
		
		if (i + t[i] <= n) dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
	}
	cout << dp[n];
}