#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int visit = 0;
	for (int i = 0; i < 28; i++) {
		int n; cin >> n;
		visit |= (1 << n);
	}

	for (int i = 1; i < 31; i++) {
		if (!(visit & (1 << i))) cout << i << "\n";
	}
}
