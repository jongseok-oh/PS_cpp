#include <iostream>

typedef long long ll;

using namespace std;

ll n;

const int MOD = 1e9 + 7;

struct Matrix { int mat[2][2];};

Matrix multipleMatrix(Matrix& a, Matrix& b) {
	Matrix ret = { 0,0,0,0 };

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		int& calc = ret.mat[i][j];

		for (int k = 0; k < 2; k++) {
			calc += 1LL * a.mat[i][k] * b.mat[k][j] % MOD;
			calc %= MOD;
		}
	}

	return ret;
}

int solve(ll t) {
	Matrix matrix = { 4,-1,1,0 };
	Matrix ret = { 1,0,0,1 };

	t--;

	while (t) {
		if (t & 1) ret = multipleMatrix(ret, matrix);

		matrix = multipleMatrix(matrix, matrix);

		t >>= 1;
	}

	return (1LL * ret.mat[0][0] * 3 + ret.mat[0][1] * 1) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	if (n & 1) {
		cout << 0; return 0;
	}

	int ans = solve(n / 2);

	if (ans < 0) ans += MOD;

	cout << ans;
}