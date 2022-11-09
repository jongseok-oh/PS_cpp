#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n,p;

int cost[16][16];
int dp[1 << 16];

int solve(int bit, int cnt) {
	if (cnt >= p) return 0;
	int& ret = dp[bit];
	if (ret != -1) return ret;
	ret = 1e9;
	
	for (int i = 0; i < n; i++) {
		if (bit & (1 << i)){
			for (int j = 0; j < n; j++) {
				if (!(bit & (1 << j)))
					ret = min(ret, solve(bit | (1 << j), cnt + 1) + cost[i][j]);
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> cost[i][j];
	
	memset(dp, -1, sizeof(dp));
	
	string state; cin >> state;

	int bit = 0, cnt = 0;

	for (int i = 0; i < n; i++) {
		if (state[i] == 'Y') {
			cnt++;
			bit |= (1 << i);
		}
	}
	cin >> p;
	if (p && !cnt) {
		cout << -1; return 0;
	}else cout << solve(bit, cnt);
}