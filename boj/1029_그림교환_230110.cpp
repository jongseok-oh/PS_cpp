#include <iostream>
#include <algorithm>

using namespace std;

int n;

string market[15];

int dp[10][15][1 << 15];

//			person			price			visit			
// 지금 몇번째 사람이고, 가격이 얼마고, 이 사람들을 거쳐왔을 때
// 앞으로 더 거칠 수 있는 사람 수
int solve(int person, int price, int visit) {
	visit |= (1 << person);
	int& ret = dp[price][person][visit];
	if (ret) return ret;
	ret = 1;
	for (int i = 0; i < n; i++) {
		if (visit & (1 << i)) continue;
		int nPrice = market[person][i] - '0';
		if (nPrice < price) continue;
		ret = max(ret, solve(i, nPrice, visit) + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> market[i];
	cout << solve(0, 0, 0);
}