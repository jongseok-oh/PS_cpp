#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
string str;

char nextPill[26];

int dp[1500][1500];

int solve(int f, int b, char t) {
	if (f > b) return 0;
	int& ret = dp[f][b];

	if (ret != -1) return ret;
	ret = 0;

	if (str[f] == t) {
		ret = max(ret, 1 + solve(f + 1, b, nextPill[t -'A']));
	}
	if (str[b] == t) {
		ret = max(ret, 1 + solve(f, b -1, nextPill[t - 'A']));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> str;
	nextPill['B' - 'A'] = 'L';
	nextPill['L' - 'A'] = 'D';
	nextPill['D' - 'A'] = 'B';

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 3 * n - 1, 'B');
}