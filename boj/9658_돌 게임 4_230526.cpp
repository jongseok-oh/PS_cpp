#include <iostream>

using namespace std;

int n;

int dp[1000];

int stone[] = { 1,3,4 };

// idx에서 시작해서 이기면 1
// 지면 -1
int solve(int idx) {
	if (idx == n) return 1;

	int& ret = dp[idx];

	if (ret) return ret;
	ret = -1;
	for (int next = 0; next < 3; next++) {
		int nStone = idx + stone[next];
		if (nStone > n) continue;

		if (solve(nStone) < 0) {
			ret = 1; break;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cout << (solve(0) == 1 ? "SK" : "CY");
}