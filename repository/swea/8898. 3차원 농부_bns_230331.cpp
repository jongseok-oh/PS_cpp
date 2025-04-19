#include <iostream>
#include <algorithm>

using namespace std;

int cow[500000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		int n, m,c1,c2; cin >> n >> m>>c1>>c2;
		for (int i = 0; i < n; i++) cin >> cow[i];

		sort(cow, cow + n);

		int _min = 0x7fffffff, cnt = 0;

		while(m--) {
			int horse; cin >> horse;

			int left = -1, right = n;

			while (left + 1 < right) {
				int mid = (left + right) >> 1;
				
				if (cow[mid] >= horse) right = mid;
				else left = mid;
			}

			if (left != -1) {
				int dist = horse - cow[left];
				if (dist < _min) {
					_min = dist; cnt = 1;
				}
				else if (dist == _min) cnt++;
			}

			if (right != n) {
				int dist = cow[right] - horse;
				if (dist < _min) {
					_min = dist; cnt = 1;
				}
				else if (dist == _min) cnt++;
			}
		}
		cout << "#" << tt<<" "<<(abs(c1-c2)+_min)<<" "<< cnt << "\n";
	}
}