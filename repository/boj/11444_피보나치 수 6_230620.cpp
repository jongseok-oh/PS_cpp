#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;
vector<vector<int>> matrix = { {1,1},{1,0} };

vector<vector<int>> multipleMatrix(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> ret(2, vector<int>(2));

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			ret[i][j] += (1LL * a[i][k] * b[k][j]) % MOD;
			ret[i][j] %= MOD;
		}
	}
	return ret;
}

vector<vector<int>> solve(long long t) {
	if (t == 1) return matrix;
	
	auto half = solve(t / 2);
	auto ret = multipleMatrix(half, half);

	return (t & 1 ? multipleMatrix(ret, matrix) : ret);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n; cin >> n;

	cout<<solve(n)[1][0];
}