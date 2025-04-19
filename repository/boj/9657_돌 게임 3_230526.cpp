#include <iostream>

using namespace std;

int n;

// i에서 시작해서 이길 수 있는가
int dp[1000];
int stone[] = { 1,3,4 };

// 이기면 1, 지면 -1
int solve(int idx) {

	if (idx == n) return -1;

	int& ret = dp[idx];

	if (ret) return ret;
	ret = -1;
	for (int dd = 0; dd < 3; dd++) {
		int nStone = idx + stone[dd];
		if (nStone > n) continue;
		
		if (solve(nStone) < 0){
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