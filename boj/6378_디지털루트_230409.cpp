#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string n;
	while (cin >> n) {
		if (n == "0") break;
		
		int digital = 0;
		for (int i = 0, len = n.size(); i < len; i++) {
			digital += n[i] - '0';
		}
		while (digital / 10) {
			int t = 0;
			while (digital) {
				t += digital % 10;
				digital /= 10;
			}
			digital = t;
		}
		cout << digital << "\n";
	}
}