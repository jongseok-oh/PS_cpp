#include <iostream>
#include <cstring>

using namespace std;

int cache[21][21][21];

int solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return solve(20,20,20);
	
	int& ret = cache[a][b][c];
	if (ret != -1) return ret;

	if (a < b && b < c)
		return ret = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);

	return
		ret = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		memset(cache, -1, sizeof(cache));

		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		cout << solve(a, b, c) << "\n";
	}
}