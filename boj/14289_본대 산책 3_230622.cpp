#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n, m, d;

vector<vector<int>> multipleMatrix(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> ret(n, vector<int>(n));

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		int& calc = ret[i][j];

		for (int k = 0; k < n; k++) {
			calc += 1LL * a[i][k] * b[k][j] % MOD;
			calc %= MOD;
		}
	}

	return ret;
}

int solve(int t, vector<vector<int>>& matrix) {
	// 단위 행렬
	vector<vector<int>> ret(n, vector<int>(n));
	for (int i = 0; i < n; i++) ret[i][i] = 1;

	while (t)
	{
		if (t & 1) ret = multipleMatrix(ret, matrix);

		matrix = multipleMatrix(matrix, matrix);
		t >>= 1;
	}

	return ret[0][0];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(n));

	while (m--) {
		int a, b; cin >> a >> b;
		a--; b--;
		
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}

	cin >> d;
	cout << solve(d, matrix);
}