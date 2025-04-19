#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n != 1) {
		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				cout << i << "\n";
				n /= i; break;
			}
		}
	}
}