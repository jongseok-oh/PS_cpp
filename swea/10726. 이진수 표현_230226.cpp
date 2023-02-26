#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, m; cin >> n >> m;
		 cout << "#"<<t<<" "<<(((((1 << n) - 1) & m) == ((1 << n) - 1))?"ON\n":"OFF\n");
	}
	return 0;
}
