#include <iostream>
#include <algorithm>

using namespace std;

int n;

int dolsang[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> dolsang[i];

	int ans = 1;

	int oneCnt, twoCnt;

	if (dolsang[n - 1] == 1) {
		oneCnt = 1;
		twoCnt = -1;
	}
	else {
		oneCnt = -1;
		twoCnt = 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (dolsang[i] == 1) {
			oneCnt = oneCnt < 0 ? 1 : oneCnt + 1;
			twoCnt--;
		}
		else {
			oneCnt--;
			twoCnt = twoCnt < 0 ? 1 : twoCnt + 1;
		}
		ans = max({ ans, oneCnt, twoCnt });
	}
	cout << ans;
}