#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;

vector<vector<int>> matrics = {
	{0,1,1,0,0,0,0,0},
	{1,0,1,1,0,0,0,0},
	{1,1,0,1,0,1,0,0},
	{0,1,1,0,1,1,0,0},
	{0,0,0,1,0,1,1,0},
	{0,0,1,1,1,0,0,1},
	{0,0,0,0,1,0,0,1},
	{0,0,0,0,0,1,1,0}
};

int D;

vector<vector<int>> multipleMatrics(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> ret(8, vector<int>(8));

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				int& t = ret[i][j];
				t += (long long)a[i][k] * b[k][j] % MOD;
				t %= MOD;
			}
		}
	}

	return ret;
}

vector<vector<int>> solve(int d) {
	if (d == 1) return matrics;

	auto t = solve(d / 2);

	auto ret = multipleMatrics(t, t);
	if (d & 1) ret = multipleMatrics(ret, matrics);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> D;
	auto ans = solve(D);
	cout << ans[0][0];
}