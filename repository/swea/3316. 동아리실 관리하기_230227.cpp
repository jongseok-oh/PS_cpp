#include <iostream>
#include <cstring>

using namespace std;

int dp[1 << 4][10000];

int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string managerStr; cin >> managerStr;
		int n = managerStr.size();
		memset(dp, 0, sizeof(dp));
		for (int day = 0; day < n; day++) {
			int todayManager = managerStr[day] - 'A';
			int mask = (1 << todayManager);

			if (!day) {
				mask |= 1;
				for (int i = 1; i < 16; i++) if ((i&mask) == mask) dp[i][0] = 1;
				continue;
			}

			for (int todayEntry = 1; todayEntry < 16; todayEntry++) {
				if ((todayEntry&mask) == mask) {
					for (int yesterdayEntry = 1; yesterdayEntry < 16; yesterdayEntry++) {
						if (todayEntry & yesterdayEntry) {
							dp[todayEntry][day] += dp[yesterdayEntry][day - 1];
							dp[todayEntry][day] %= mod;
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i < 16; i++) {
			ans += dp[i][n - 1];
			ans %= mod;
		}
		cout << "#" << t << " " << ans << "\n";
	}
}
