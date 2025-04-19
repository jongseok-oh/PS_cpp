#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	int sum = 0, twoCnt = 0;
	for (int i = 0; i < n; i++) {
		int tree; cin >> tree;
		sum += tree;
		twoCnt += tree / 2;
	}

	if (sum % 3) cout << "NO";
	else {
		if (twoCnt >= sum / 3) cout << "YES";
		else cout << "NO";
	}
}