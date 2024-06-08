#include <iostream>
#include <algorithm>

using namespace std;

int D, P, Q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> D >> P >> Q;
	if (P > Q) swap(P, Q);

	int ret = 0x7fffffff;
	for (int i = 0, n = min(D / Q, P)+1; i <= n; ++i) {
		int temp = i * Q, remain = D - temp;
		if (remain > 0) temp += (remain + P - 1) / P * P;
		ret = min(ret, temp);
	}
	cout << ret;
}