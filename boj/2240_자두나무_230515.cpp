#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t,w;

int dp[1000][31][2];

bool jadu[1000];

int solve(int time, bool loc, int moveCnt) {
	if (time == t) return 0;

	int& ret = dp[time][moveCnt][loc];

	if (ret != -1) return ret;

	ret = 0;

	ret = solve(time + 1, loc, moveCnt) + (jadu[time] == loc ? 1 : 0);

	if (moveCnt)
		ret = max(ret, solve(time + 1, !loc, moveCnt - 1)
			+ (jadu[time] == !loc ? 1 : 0));
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t>>w;

	for (int i = 0; i < t; i++) {
		int tjadu; cin >> tjadu;
		jadu[i] = tjadu - 1;
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0, w);
}