#include <iostream>
#include <algorithm>

using namespace std;

int rest_area[52];

int n, m, l;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> l;

	for (int i = 1; i <= n; i++) cin >> rest_area[i];
	sort(rest_area + 1, rest_area + n + 1, [](int& a, int& b) {return a < b; });
	rest_area[n+1] = l;
	int left = 0, right = l -1; // 최대 길이
	while (left + 1 < right) {
		int cnt = 0;

		int mid = (left + right) >> 1;

		for (int i = 0; i <= n; i++) cnt += (rest_area[i + 1] - rest_area[i] - 1) / mid;

		if (cnt > m) left = mid;
		else right = mid;
	}
	cout << right;
}