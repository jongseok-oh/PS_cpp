#include <iostream>
#include <algorithm>

using namespace std;

int n, m, r;

int roads[100][100];
int items[100];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) cin >> items[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) roads[i][j] = 1e9;

	while (r--) {
		int a, b, l; cin >> a >> b >> l;
		a--; b--;
		roads[a][b] = l;
		roads[b][a] = l;
	}

	for (int mid = 0; mid < n; mid++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				roads[i][j] = min(roads[i][j], roads[i][mid] + roads[mid][j]);
			}
		}
	}

	int ans = -1;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i == j || roads[i][j] <= m) sum += items[j];
		}
		ans = max(ans, sum);
	}
	cout << ans;
}
