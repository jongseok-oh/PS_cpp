#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct item
{
	int w, v;
};

int n,k;

item product[100];
int dp[100][100001];

int solve(int i, int j) {
	if (i >= n) return 0;
	int& ret = dp[i][j];
	if (ret != -1) return ret;
	ret = solve(i + 1, j);
	if (j + product[i].w <= k)
		ret = max(ret, solve(i + 1, j + product[i].w) + product[i].v);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> product[i].w >> product[i].v;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
}
