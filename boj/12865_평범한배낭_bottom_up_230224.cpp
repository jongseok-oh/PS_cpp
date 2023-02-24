#include <iostream>
#include <algorithm>

using namespace std;

struct item
{
	int w, v;
};

int n,k;

item product[100];

// 배열의 정의
// dp[i][j]
// 물건이 i개있고, 배낭의 최대 기용 용량이 j일 때
// 최대의 가치
int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> product[i].w >> product[i].v;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			// i번 째 물건을 배낭에 넣지 않는다
			dp[i][j] = dp[i - 1][j];
			if (j >= product[i - 1].w) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - product[i - 1].w] + product[i - 1].v);
			}
		}
	}

	cout << dp[n][k];
}
