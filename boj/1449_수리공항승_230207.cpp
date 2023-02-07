#include <iostream>
#include <algorithm>

using namespace std;

int n,l;

int tapes[1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>l;

	for (int i = 0; i < n; i++) cin >> tapes[i];
	sort(tapes, tapes + n);

	int end = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (tapes[i] > end) {
			ans++; end = tapes[i] + l - 1;
		}
	}

	cout << ans;
}
