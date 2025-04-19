#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll dp[100][100];

int n;

int map[100][100];

ll solve(int y, int x) {
	if (y == n - 1 && x == n - 1) return 1;
	
	ll& ret = dp[y][x];

	if (ret != -1) return ret;

	ret = 0;

	int jump = map[y][x];

	if (y + jump < n) ret += solve(y + jump, x);
	if (x + jump < n) ret += solve(y, x + jump);
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> map[i][j];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0);
}