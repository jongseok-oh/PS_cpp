#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int T, N, D;

struct Matrix
{

	vector<vector<int>> map;

	Matrix() {
		map = vector<vector<int>>(20, vector<int>(20));
	}

	Matrix(int n) {
		map = vector<vector<int>>(n, vector<int>(n));
	}

	void setLine(int a, int b, int c) {
		map[a][b] = c;
	}

	Matrix operator * (const Matrix& other) {
		Matrix ret = Matrix(N);

		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
			{
				ret.map[i][j] += 1LL * map[i][k] * other.map[k][j] % MOD;
				ret.map[i][j] %= MOD;
			}
		}

		return ret;
	}

	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cout << map[i][j] << " ";
			cout << "\n";
		}
	}
};

vector<Matrix> maps;

Matrix DEFAULT;

Matrix calcDeafaultMatrix() {
	Matrix ret = Matrix(N);
	for (int i = 0; i < N; i++) ret.setLine(i, i, 1);

	for (auto& map : maps) ret = ret * map;

	return ret;
}

Matrix fastMultiple(int n) {
	Matrix ret = Matrix(N);
	for (int i = 0; i < N; i++) ret.setLine(i, i, 1);

	while (n) {
		if (n & 1) ret = ret * DEFAULT;
		
		DEFAULT = DEFAULT * DEFAULT;
		n >>= 1;
	}

	return ret;
}

Matrix calcDiv(int div) {
	Matrix ret = Matrix(N);
	for (int i = 0; i < N; i++) ret.setLine(i, i, 1);

	for (int i = 0; i < div; i++) ret = ret * maps[i];

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T >> N >> D;

	for (int i = 0; i < T; i++) {
		int len; cin >> len;
		Matrix mat = Matrix(N);

		for (int j = 0; j < len; j++) {
			int a, b, c; cin >> a >> b >> c;
			mat.setLine(--a, --b, c);
		}

		maps.push_back(mat);
	}

	DEFAULT = calcDeafaultMatrix();
	(fastMultiple(D/T) * calcDiv(D%T)).print();
}