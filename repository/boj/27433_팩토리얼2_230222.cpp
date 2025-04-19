#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	long long ans = 1;
	for (int i = 1; i <=n; i++) ans *= i;
	cout << ans;
}
