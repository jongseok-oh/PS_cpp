#include <iostream>
#include <algorithm>

using namespace std;

int n;

int nums[100000];

// dp[i][j] = i에서 시작했을 때 숫자
// 제거를 쓴 경우, 안쓴 경우
// 가장 큰 연속 합
int dp[100001][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	if (n == 1) { cout << nums[0]; return 0; }

	int ans = -1e9;

	dp[n][0] = -1e9, dp[n][1] = -1e9;

	for (int i = n - 1; i >= 0; i--) {
		
		// i + 1로 시작하는 연속합이 음수이면
		// 더할 필요가 없다
		int beforeNum = dp[i + 1][0] < 0 ? 0 : dp[i + 1][0];
		int beforeUsedNum = dp[i + 1][1] < 0 ? 0 : dp[i + 1][1];

		// 숫자 삭제를 쓰지 않는 경우
		dp[i][0] = nums[i] + beforeNum;

		// 과거에 숫자 삭제 쓴 경우, 지금 숫자 삭제 쓴 경우
		// 지금 숫자 삭제 시에는
		// 최소 하나의 수를 뽑아야 하므로 dp 과거 값을 참조해야함.
		dp[i][1] = max(nums[i] + beforeUsedNum, dp[i + 1][0]);

		ans = max({ ans,dp[i][0], dp[i][1] });
	}

	cout << ans;
}