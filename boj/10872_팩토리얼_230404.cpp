#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	long long ret = 1;

	for (int i = 1; i <= n; i++) ret *= i;
	cout << ret;
}