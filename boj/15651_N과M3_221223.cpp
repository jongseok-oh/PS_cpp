#include <iostream>

using namespace std;

int n, m;

int arr[7];

void solve(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n"; return;
	}

	for (int i = 1; i <= n; i++) {
		arr[idx] = i;
		solve(idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	solve(0);
}