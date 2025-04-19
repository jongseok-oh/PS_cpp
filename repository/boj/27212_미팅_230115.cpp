#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int n, m, c;

ll w[17][17];

int a[1000], b[1000];

ll dp[1000][1000];

// aStart번째, bStart번째에서 시작했을 때
// 악수의 만족도 최대값 리턴
ll solve(int aStart, int bStart) {
	if (aStart >= n || bStart >= m) return 0;
	ll& ret = dp[aStart][bStart];
	if (ret != -1) return ret;

	// a를 그냥 스킵
	ret = max(ret, solve(aStart + 1, bStart));
	
	// a랑 b랑 악수하고 넘어감
	ret = max(ret, solve(aStart + 1, bStart + 1) + w[a[aStart]][b[bStart]]);

	// b를 스킵
	ret = max(ret, solve(aStart, bStart + 1));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++) for (int j = 1; j <= c; j++) cin >> w[i][j];

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0);
}