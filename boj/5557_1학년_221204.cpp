#include <iostream>

using namespace std;

typedef long long ll;

int n;
int nums[100];
int ans;

ll dp[21][100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) cin >> nums[i];
	cin >> ans;

	dp[nums[0]][0] = 1;

	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j + nums[i] <= 20) {
				dp[j + nums[i]][i] += dp[j][i - 1];
			}
			if (j - nums[i] >= 0) {
				dp[j - nums[i]][i] += dp[j][i - 1];
			}
		}
	}
	cout << dp[ans][n-2];
}