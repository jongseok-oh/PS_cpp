#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
int n, m;

// dp[i][j] = a[i], b[j]에서 시작하는
// substring의 lcs
int dp[1001][1001];

void trace(int i, int j) {
	if (i >= n || j >= m) return;
	if (a[i] == b[j]) {
		cout << a[i];
		trace(i + 1, j + 1);
	}
	else {
		if (dp[i][j + 1] > dp[i + 1][j]) trace(i, j + 1);
		else trace(i+1, j);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	n = a.size(), m = b.size();
	
	for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) {
		int& t = dp[i][j];
		if (a[i] == b[j]) t = dp[i+1][j+1] + 1;
		else t = max(dp[i][j + 1], dp[i + 1][j]);
	}

	cout << dp[0][0];
	if (dp[0][0]) {
		cout << "\n";
		trace(0, 0);
	}
}