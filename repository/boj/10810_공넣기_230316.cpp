#include <iostream>

using namespace std;

int bucket[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	
	while (m--) {
		int a, b, c; cin >> a >> b >> c;

		for (int i = a; i <= b; i++) bucket[i] = c;
	}

	for (int i = 1; i <= n; i++) cout << bucket[i] << " ";
}