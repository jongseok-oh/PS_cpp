#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

string a[500000], b[500000], ans[500000];

int bns(const string& tar) {
	int low = -1, high = m;
	
	while (low + 1 < high) {
		int mid = (low + high) >> 1;
		if (b[mid] >= tar) high = mid;
		else low = mid;
	}
	return high;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + m);

	int answer = 0;

	for (int i = 0; i < n; i++) {
		int idx = bns(a[i]);
		if (idx == m || b[idx] != a[i]) continue;
		ans[answer++] = a[i];
	}
	cout << answer << "\n";
	for (int i = 0; i < answer; i++) cout << ans[i] << "\n";
}