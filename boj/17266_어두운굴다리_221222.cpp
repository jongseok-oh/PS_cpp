#include <iostream>

using namespace std;

int n,k;

int bridge[100000];

bool chk(int tar) {
	int left = 0;

	for (int i = 0; i < k; i++) {
		if (bridge[i] - tar > left) return false;
		left = bridge[i] + tar;
	}
	if (bridge[k - 1] + tar >= n) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 0; i < k; i++) cin >> bridge[i];

	int low = 0, high = n;

	while (low + 1 < high) {
		int mid = (low + high) >> 1;

		if (chk(mid)) high = mid;
		else low = mid;
	}
	cout << high;
}