#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;

pii items[1500];
int len = 0;

int dp[10001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	int v, c, k;
	for (int i = 0; i < n; i++) {
		cin >> v >> c >> k;
		for (int j = k; k > 0; j >>= 1) {
			int num = j - (j >> 1);
			items[len++] = { v*num, c*num };
			k -= num;
		}
	}

	for (int i = 0; i < len; i++) {
		int v = items[i].first,
			c = items[i].second;
		for (int j = m; j >= v; j--) {
			dp[j] = max(dp[j], dp[j - v] + c);
		}
	}
	cout << dp[m];
}