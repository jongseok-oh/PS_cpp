#include <iostream>

using namespace std;

int n,m;

int dp[41];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>m;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < 41; i++) 
		dp[i] = dp[i - 1] + dp[i - 2];

	int ans = 1;
	int temp = 0;
	for (int i = 0; i < m; i++) {
		int vvip; cin >> vvip;
		ans *= dp[vvip - temp -1];
		temp = vvip;
	}

	if(temp != n) ans *= dp[n - temp];

	cout << ans;
}