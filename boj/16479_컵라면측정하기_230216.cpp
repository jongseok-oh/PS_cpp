#include <iostream>

using namespace std;

int k, d1, d2;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k >> d1 >> d2;
	double b = ((double)d2 - d1) * ((double)d2 - d1) / 4;
	cout << ((double)k * k - b);
}
