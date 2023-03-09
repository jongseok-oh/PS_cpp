#include <iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b;

	int ret = 0;

	int times = 1;
	
	for (int i = 0; i < 3; i++) {
		int t = b % 10 * a;
		cout <<t<< "\n";
		ret += t * times;
		b /= 10;
		times *= 10;
	}
	cout << ret;
}