#include <iostream>
using namespace std;

int n;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	n /= 4;
	while (n--) cout << "long ";
	cout << "int";
}