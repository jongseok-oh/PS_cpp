#include <iostream>

using namespace std;

int a, b;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	cout << (a > b?">":(a == b?"==":"<"));
}