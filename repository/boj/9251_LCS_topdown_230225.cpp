#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string a, b;
int n, m;

int dp[1000][1000];

int solve(int aidx, int bidx) {
	if (aidx >= n || bidx >= m) return 0;
	int& ret = dp[aidx][bidx];
	if (ret != -1) return ret;
	if (a[aidx] == b[bidx]) ret = 1 + solve(aidx + 1, bidx + 1);
	else {
		ret = max({ ret, solve(aidx + 1, bidx), solve(aidx, bidx + 1)});
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	n = a.size(), m = b.size();
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0);
}