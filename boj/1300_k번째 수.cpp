#include <iostream>
#include <algorithm>
using namespace std;
long long n,k;

bool check(long long mid) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += min(mid/i, n);
	}
	return sum >= k;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>k;

	long long low = 0, high = n * n;

	while (low + 1 < high) {
		long long mid = (low + high) >> 1;
		if (check(mid)) high = mid;
		else low = mid;
	}
	cout << high;
}