#include <iostream>
#include <math.h>

using namespace std;

int T,n;

bool sosu[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 2, len = sqrt(1000000); i <= len; i++) {
		if (!sosu[i]) {
			for (int j = i + i; j <= 1000000; j += i)
				sosu[j] = true;
		}
	}

	cin >> T;
	while (T--) {
		cin >> n;
		int cnt = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (!sosu[i] && !sosu[n - i])cnt++;
		}
		cout << cnt << "\n";
	}
}