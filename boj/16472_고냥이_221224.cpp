#include <iostream>
#include <algorithm>

using namespace std;

int n;
int alpha[26];
string t;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>> t;

	int cnt = 0, ans = -1;
	for (int l = 0, r = -1,len = t.size(); l < len; l++) {
		while (r + 1 < len) {
			if (!alpha[t[r + 1] - 'a']) {
				if (cnt + 1 > n) break;
				cnt++;
			}
			alpha[t[++r] - 'a']++;
		}
		ans = max(ans, r - l + 1);
		if (!--alpha[t[l] -'a']) cnt--;
	}
	cout << ans;
}