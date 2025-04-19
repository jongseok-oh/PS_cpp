#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int cardA[2000], cardB[2000];

int dp[2000][2000];

int solve(int a, int b) {
	if (a >= n || b >= n) return 0;
	
	int& ret = dp[a][b];

	if (ret != -1) return ret;

	ret = 0;
	ret = max({solve(a + 1, b), solve(a + 1, b + 1),
		(cardA[a] <= cardB[b]?0 : cardB[b]+ solve(a, b+1))});

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> cardA[i];
	for (int i = 0; i < n; i++) cin >> cardB[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
}
