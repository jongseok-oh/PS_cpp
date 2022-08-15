#include <iostream>
using namespace std;

int n;
int chu[30];
bool dp[30][30001] = {false,};

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i <n; i++) cin >> chu[i];

	int sum = chu[0];
	dp[0][chu[0] + 15000] = true;
	dp[0][15000] = true;
	dp[0][15000 - chu[0]] = true;
	
	for (int i = 1; i <n; i++) {
		for (int j = 15000 - sum; j <= sum + 15000; j++) {
			if (dp[i-1][j]) {
				dp[i][j + chu[i]] = true;
				dp[i][j] = true;
				dp[i][j - chu[i]] = true;
			}
		}
		sum += chu[i];
	}

	int bizzCnt; cin >> bizzCnt;
	while (bizzCnt--) {
		int bizz; cin >> bizz;
		if (bizz > 15000) {
			cout << "N" << " "; continue;
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (dp[i][bizz + 15000]) {
				cout << "Y" << " ";
				flag = false;  break;
			}
		}
		if(flag) cout << "N" << " ";
	}
}