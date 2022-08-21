#include <iostream>

using namespace std;
int n, s;
int num[20];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];

	int cnt = 0;

	for (int i = 1, len = (1 << n); i < len; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += (i & (1 << j)) ? num[j] : 0;
		}
		if (sum == s) cnt++;
	}
	cout << cnt;
}