#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// start -> end
bool dp[2501][2501];

string str;

int n;

// dp2[i] = i에서 시작할 때
// 펠린드롬 분할의 최소 값
int dp2[2500];

int solve(int idx) {
	if (idx == n) return 0;

	int& ret = dp2[idx];

	if (ret) return ret;

	ret = 1e9;

	for (int i = idx; i < n; i++) {
		if (dp[idx][i]) {
			ret = min(ret, 1 + solve(i + 1));
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str;
	n = str.size();

	for (int j = 0; j < n; j++) {
		for (int i = j + 1; i >= 0; i--) {
			if (i == j + 1 || i == j) dp[i][j] = true;
			else if (str[i] == str[j] && dp[i + 1][j - 1])
				dp[i][j] = true;
		}
	}

	cout << solve(0);
}