#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e3;

struct Matrix{int mat[2][2];};

Matrix mult(Matrix& a, Matrix& b) {
	Matrix ret = { 0,0,0,0 };

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		int& calc = ret.mat[i][j];

		for (int k = 0; k < 2; k++) {
			calc += a.mat[i][k] * b.mat[k][j];
			calc %= MOD;
		}
	}

	return ret;
}

int solve(int n) {
	Matrix matrix = { 3,5,1,3 };
	Matrix ret = { 1,0,0,1 };
	
	while (n) {
		if (n & 1) ret = mult(ret, matrix);
		matrix = mult(matrix, matrix);
		n >>= 1;
	}

	return ((ret.mat[0][0] * 3 + ret.mat[0][1]) * 2 - 1) % MOD;
}

void print(int test, int ans) {

	int temp = ans;

	int size = 0;

	while (temp) {
		temp /= 10;
		size++;
	}

	cout << "Case #" << test << ": ";
	for (int i = 0; i < 3 - size; i++) cout << 0;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n; cin >> n;

		print(tt, solve(n - 1));
	}
}