#include <iostream>
using namespace std;

int n;
int chu[30];
bool dp[31][15001] = {false,};

// 배열을 두배 크기로 만들어 음수를 처리하는게 아닌
// 절대값을 통해 caching 할 수 있다.
// 값을 쓰는 과정이 idx를 한칸 키우면서 발생하므로
// dp의 크기를 max size보다 하나 더 키워서 사용

void caching(int idx, int w) {
	if (idx > n || dp[idx][w])return;
	dp[idx][w] = true;
	caching(idx + 1, w + chu[idx]);
	caching(idx + 1, w);
	caching(idx + 1, abs(w - chu[idx]));
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> chu[i];

	caching(0, 0);
	int bizzCnt; cin >> bizzCnt;

	while (bizzCnt--) {
		int bizz; cin >> bizz;
		if (bizz > 15000) cout << "N" << " ";
		else if (dp[n][bizz]) cout << "Y" << " ";
		else cout << "N" << " ";
	}
}