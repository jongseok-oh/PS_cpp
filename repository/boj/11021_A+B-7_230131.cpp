#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T,a,b; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> a >> b;
		cout << "Case #" << t << ": " << a + b << "\n";
	}
}