#include <iostream>
#include <vector>

using namespace std;

int n, s, e, t;
int MOD = 1000003;

vector<vector<int>> multipleMatrix(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2) {
	vector<vector<int>> ret(n * 5, vector<int>(n * 5));

	for (int i = 0; i < n * 5; i++) for (int j = 0; j < n * 5; j++) {
		int& loc = ret[i][j];

		for (int k = 0; k < 5 * n; k++) {
			loc += (1LL * matrix1[i][k] * matrix2[k][j]) % MOD;
			loc %= MOD;
		}
	}
	return ret;
}

vector<vector<int>> pow(vector<vector<int>>& matrix, int t) {
	if (t == 1) return matrix;

	auto half = pow(matrix, t / 2);
	auto ret = multipleMatrix(half, half);

	return (t & 1 ? multipleMatrix(ret, matrix) : ret);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s >> e >> t;
	s--; e--;

	vector<vector<int>> matrix(n * 5, vector<int>(n * 5));

	// 정점 분할
	for (int i = 0; i < n; i++)
		for (int j = 1; j < 5; j++)
			matrix[i * 5 + j][i * 5 + j - 1] = 1;

	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		char time; cin >> time;
		int num = time - '0';

		// 분할 정점에 연결
		if (num) matrix[i * 5][j * 5 + num - 1] = 1;
	}

	cout << pow(matrix, t)[s * 5][e * 5];
}