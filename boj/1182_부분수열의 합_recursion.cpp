#include <iostream>

using namespace std;
int n, s;
int num[20];
int cnt = 0;

void solve(int idx, int sum) {
	if (sum + num[idx] == s) cnt++;
	if (idx == n - 1) return;

	solve(idx + 1, sum);
	solve(idx + 1, sum + num[idx]);
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];
	solve(0, 0);
	cout << cnt;
}