#include <iostream>

using namespace std;

int n, m;

int board[1025][1025];
int prefix_sum[1025][1025];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		cin >> board[i][j];
		prefix_sum[i][j] = prefix_sum[i][j - 1] + board[i][j];
	}
	while (m--) {
		int query; cin >> query;
		if (query) {
			int Y1, X1, Y2, X2;
			cin >> Y1 >> X1 >> Y2 >> X2;
			int ans = 0;
			for (int i = Y1; i <= Y2; i++) {
				ans += prefix_sum[i][X2] - prefix_sum[i][X1 - 1];
			}
			cout << ans<<"\n";
		}
		else {
			int Y, X, C;
			cin >> Y >> X >> C;
			int diff = C - board[Y][X];
			board[Y][X] = C;
			for (int i = X; i <= n; i++) {
				prefix_sum[Y][i] += diff;
			}
		}
	}
	// sumQuery = n * m,
	// updateQuery = n * m
	// -> O(n*m)
}