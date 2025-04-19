#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int vec1[800], vec2[800];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T,n; cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> vec1[i];
		for (int i = 0; i < n; ++i) cin >> vec2[i];
		sort(vec1, vec1 + n);
		sort(vec2, vec2 + n, [&](int& a, int& b) {
			return a > b;
		});

		long long ret = 0;
		for (int i = 0; i < n; ++i) {
			ret += 1LL * vec1[i] * vec2[i];
		}

		cout << "Case #" << t << ": " << ret << "\n";
	}
}