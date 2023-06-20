#include <iostream>
#include <vector>

using namespace std;

int T, n;

vector<vector<int>> matrix = { {3,5}, {1,3} };

vector<vector<int>> multipleMatrix(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> ans(2, vector<int>(2));

	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++)
		{
			ans[i][j] += (a[i][k] * b[k][j]) % 1000;
			ans[i][j] %= 1000;
		}
	}

	return ans;
}

vector<vector<int>> solve(int t) {
	if (t == 1) return matrix;

	auto half = solve(t / 2);
	auto ret = multipleMatrix(half, half);

	return t & 1 ? multipleMatrix(ret, matrix) : ret;
}

void print(int ans, int t) {
	int temp = ans;
	int size = 0;
	
	while (temp) {
		temp /= 10;
		size++;
	}
	cout << "Case #" << t << ": ";
	for (int i = 0; i < 3 - size; i++) cout << 0;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		auto mat = solve(n - 1);

		int ans = ((mat[0][0] * 3 + mat[0][1]) * 2 - 1) % 1000;
		print(ans, t);
	}
}