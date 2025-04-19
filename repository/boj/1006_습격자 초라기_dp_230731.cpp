#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int T, n, w;

int enemy[10000][2];

int dp[10000][4][4];

int solve(int idx, int tBit, int startBit) {
	if (idx == n) {
		// 2 - 빵꾸난 부분의 개수
		startBit |= tBit;
		int cnt = 0;
		for (int i = 0; i < 2; i++) if (startBit & (1 << i)) cnt++;
		return 2 - cnt;
	}

	int& ret = dp[idx][tBit][startBit];

	if (ret != -1) return ret;

	ret = 1e9;

	// 시작을 비우고 가는 경우
	if (idx == 0) {
		// 둘 다 비우기
		ret = min(ret, solve(idx + 1, 0, 0));
		// 아래 점 찍기
		ret = min(ret, 1 + solve(idx + 1, 0, 1));
		// 아래 가로 놓기
		if(enemy[0][0] + enemy[1][0] <= w)
			ret = min(ret, 1 + solve(idx + 1, 1, 1));
		// 위 점 찍기
		ret = min(ret, 1 + solve(idx + 1, 0, 2));
		// 위 가로 놓기
		if (enemy[0][1] + enemy[1][1] <= w)
			ret = min(ret, 1 + solve(idx + 1, 2, 2));
	}

	// 세로로 하나 놓기
	if (tBit == 0 && enemy[idx][0] + enemy[idx][1] <= w)
		ret = min(ret, (1  + solve(idx + 1, 0, startBit)));

	int tCnt = 0;
	
	vector<int> underLine, upperLine;

	underLine.push_back(0);
	upperLine.push_back(0);

	// 아랫 줄 가능한 경우 계산
	if (!(tBit & 1)) {
		tCnt++;
		if(enemy[idx][0] + enemy[(idx + 1)%n][0] <= w)
			underLine.push_back(1);
	}

	// 윗 줄 가능한 경우 계산
	if (!(tBit & 2)){
		tCnt++;
		if (enemy[idx][1] + enemy[(idx + 1) % n][1] <= w)
			upperLine.push_back(2);
	}

	for (int i = 0; i < underLine.size(); i++) for (int j = 0; j < upperLine.size(); j++)
		ret = min(ret, tCnt + solve(idx + 1, underLine[i] | upperLine[j], startBit));

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;

	while (T--) {
		cin >> n >> w;
		
		for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++)
			cin >> enemy[j][i];

		memset(dp, -1, sizeof dp);
		if (n == 1) {
			if (enemy[0][1] + enemy[0][0] <= w) cout << 1 << "\n";
			else cout << 2 << "\n";
			continue;
		}
		cout << solve(0, 0, 3) << "\n";
	}
}