#include <iostream>

using namespace std;

typedef long long ll;

int n; ll m;

ll candies[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> candies[i];

		ll left = 0, right = 1e18; right++;
		while (left + 1 < right) {
			// 만드려는 가방의 수
			ll mid = (left + right) >> 1;
			ll sum = 0;

			// mid개의 가방을 만들 때
			// 각 가방에 몇개씩 담을 수 있는가
			for (int i = 0; i < n; i++) sum += candies[i] / mid;
			
			if (sum < m) right = mid;
			else left = mid;
		}
		cout << "#" << tt << " " << left << "\n";
	}
}