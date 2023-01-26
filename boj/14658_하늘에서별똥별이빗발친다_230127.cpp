#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, l, k;

pii stars[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> l >> k;
	for (int i = 0; i < k; i++) cin >> stars[i].first >> stars[i].second;

	int ans = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			int cnt = 0;
			int lx = stars[i].second, rx = min(lx + l, m),
				uy = stars[j].first, dy = min(uy + l, n);

			for (int z = 0; z < k; z++)
			{
				pii c = stars[z];
				if (c.first >= uy && c.first <= dy
					&& c.second >= lx && c.second <= rx) cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	cout << k - ans;
}