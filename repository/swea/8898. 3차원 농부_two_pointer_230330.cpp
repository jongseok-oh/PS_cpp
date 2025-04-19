#include <iostream>
#include <algorithm>

using namespace std;

int cow[500000], horse[500000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n, m,c1,c2; cin >> n >> m>>c1>>c2;
		for (int i = 0; i < n; i++) cin >> cow[i];
		for (int i = 0; i < m; i++) cin >> horse[i];

		sort(cow, cow + n);
		sort(horse, horse + m);

		int _min = 1e9, ans = 0;

		int cIdx = 0, hIdx = 0;
		while (cIdx < n && hIdx < m) {
			int diff = cow[cIdx] - horse[hIdx];

			int absDiff = abs(diff);
			if (absDiff < _min) {
				_min = absDiff; ans = 1;
			}
			else if (absDiff == _min) ans++;

			if (diff < 0) cIdx++;
			else hIdx++;
		}
		cout << "#" << tt<<" " <<(abs(c1-c2)+_min)<<" "<< ans << "\n";
	}
}