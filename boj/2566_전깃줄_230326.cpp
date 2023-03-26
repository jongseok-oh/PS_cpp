#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct loc
{
	int a, b;
}lines[100];

int dp[100][501];

int m;

int solve(int idx, int tline) {
	if (idx >= m) return 0;
	int& ret = dp[idx][tline];
	
	if (ret != -1) return ret;

	ret = solve(idx + 1, tline);
	if (lines[idx].b > tline) ret = max(ret, solve(idx + 1, lines[idx].b) + 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m;
	for (int i = 0; i < m; i++) cin >> lines[i].a >> lines[i].b;

	sort(lines, lines + m, [](loc& a, loc& b) {
		if (a.a == b.a) return a.b < b.b;
		return a.a < b.a;
	});

	memset(dp, -1, sizeof(dp));

	cout << m - solve(0, 0);
}