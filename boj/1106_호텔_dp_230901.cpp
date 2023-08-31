#include <iostream>

using namespace std;

int c, n;

int money[20];
int cust[20];

int dp[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> c >> n;

	for (int i = 0; i < n; i++) {
		cin >> money[i] >> cust[i];

		int loc = min(cust[i], c);

		if (!dp[loc] || dp[loc] > money[i]) dp[loc] = money[i];
	}

	for (int i = 1; i < c; i++) {
		if (!dp[i]) continue;
		for (int city = 0; city < n; city++) {
			int next = min(i + cust[city], c);

			if (!dp[next] || dp[i] + money[city] < dp[next])
				dp[next] = dp[i] + money[city];
		}
	}

	cout << dp[c];
}