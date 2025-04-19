#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll a, b;
const int MOD = 1e9;

struct Matrix {int mat[2][2];};

Matrix multipleMatrix(Matrix& matrix1, Matrix& matrix2) {
	Matrix ret = {0,0,0,0};
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		int& t = ret.mat[i][j];
		for (int k = 0; k < 2; k++)
		{
			t += 1LL * matrix1.mat[i][k] * matrix2.mat[k][j] % MOD;
			t %= MOD;
		}
	}
	return ret;
}

Matrix getFibo(ll t) {

	Matrix matrix = {1,1,1,0};

	Matrix ret = {1,0,0,1};

	while (t) {
		if (t & 1) ret = multipleMatrix(ret, matrix);

		matrix = multipleMatrix(matrix, matrix);
		t >>= 1;
	}

	return ret;
}

// 1 ~ k까지의 피보나치 합
int fiboSum(ll k) {
	if (k == 0) return 0;

	auto matrix = getFibo(k-1);
	return (1LL * 2 * matrix.mat[0][0] + matrix.mat[1][0] - 1) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;

	int ans = fiboSum(b) - fiboSum(a - 1);

	if (ans < 0) ans += MOD;

	cout << ans;
}