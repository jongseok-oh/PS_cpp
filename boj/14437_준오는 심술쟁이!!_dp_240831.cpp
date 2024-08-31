#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int s;
string str;

int dp[3000][3001];

int solve(int idx, int remain) {
	if (remain == 0) return 1;
	if (idx == str.size()) return 0;

	int& ret = dp[idx][remain];
	if (ret != -1) return ret;

	ret = 0;
	for (int k = 0, _k = min(25, remain); k <= _k; ++k) {
		ret += solve(idx + 1, remain - k);
		ret %= MOD;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);	
	cin >> s >> str;
	memset(dp, -1, sizeof dp);
	cout << solve(0, s);
};
