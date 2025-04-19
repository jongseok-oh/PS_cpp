#include <iostream>
using namespace std;

int x, n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x >> n;

	int sum = 0;
	while (n--) {
		int a, b; cin >> a >> b;
		sum += a * b;
	}
	cout << (x == sum ? "Yes" : "No");
}