#include <iostream>
using namespace std;

long long a, b, c;

long long solve( long long b) {
	if (b == 0) return 1;

	long long half = b / 2;
	
	long long t = solve(half);
	return b & 1 ? t * t % c * a % c : t * t % c;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> c;

	cout << solve(b);
}