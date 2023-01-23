#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string a,b;

void solve(string a, string b) {
	int max_len = max(a.size(), b.size());

	vector<int> _a(max_len);
	vector<int> _b(max_len);
	vector<int> ans(max_len + 1);

	for (int i = a.size() - 1; i >= 0; i--) _a[a.size() - i - 1] = a[i] - '0';
	for (int i = b.size() - 1; i >= 0; i--) _b[b.size() - i - 1] = b[i] - '0';

	for (int i = 0; i < max_len; i++) {
		ans[i + 1] = (ans[i] + _a[i] + _b[i]) / 10;
		ans[i] = (ans[i] + _a[i] + _b[i])%10;
	}
	if (ans[max_len]) cout << ans[max_len];
	for (int i = max_len - 1; i >= 0; i--) cout << ans[i];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;

	solve(a, b);
}