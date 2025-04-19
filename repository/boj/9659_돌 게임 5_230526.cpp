#include <iostream>

using namespace std;

long long n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	if (n % 4 == 1 || n % 4 == 3) cout << "SK";
	else cout << "CY";
}