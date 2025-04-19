#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int k;

int prefixSum[501];
int dp[500][500];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--)
	{
		cin >> k;
		int file;
		for (int i = 1; i <= k; ++i) {
			cin >> file;
			prefixSum[i] = prefixSum[i - 1] + file;
		}
		memset(dp, 0, sizeof dp);

		for (int diff = 1; diff <k; ++diff) {
			for (int start = 0; start + diff < k; ++start) {
				int end = start + diff;
				int& ret = dp[start][end] = 1e9;
				int cost = prefixSum[end+1] - prefixSum[start];

				for (int mid = start; mid < end; ++mid) {
					ret = min(ret, cost + dp[start][mid] + dp[mid + 1][end]);
				}
			}
		}

		cout << dp[0][k - 1] << "\n";
	}
}