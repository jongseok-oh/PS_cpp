#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[100000];

int n, m;

bool bns(string tar) {
	int left = -1, right = n - 1;
	while (left + 1 < right) {
		int mid = (left + right) >> 1;
		
		if (arr[mid] == tar) return true;
		
		if (arr[mid] > tar) right = mid;
		else left = mid;
	}
	return arr[right] == tar;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n >> m;
		
		for (int i = 0; i < n; i++) cin >> arr[i];

		sort(arr, arr + n);
		int ans = 0;
		while (m--) {
			string t; cin >> t;
			if (bns(t)) ans++;
		}
		cout << "#" << tt << " " << ans << "\n";
	}
}