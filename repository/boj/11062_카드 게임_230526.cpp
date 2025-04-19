#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int prefixSum[1001];

int dp[1001][1001];

// 카드가 left부터 right까지 남아 있을 때
// 얻을 수 있는 최대 점수
int solve(int left, int right) {
	if (left == right) return prefixSum[left] - prefixSum[left - 1];

	int& ret = dp[left][right];

	if (ret != -1) return ret;

	// left부터 right까지 점수 합
	int tsum = prefixSum[right] - prefixSum[left - 1];

	ret = max(tsum - solve(left + 1, right), tsum -  solve(left, right - 1));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int card; cin >> card;
			prefixSum[i] = prefixSum[i - 1] + card;
		}
		memset(dp, -1, sizeof(dp));
		
		cout << solve(1, n) << "\n";
	}
}