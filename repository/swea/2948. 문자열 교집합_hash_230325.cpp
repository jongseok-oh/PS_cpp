#include <iostream>
#include<unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n, m; cin >> n >> m;
		unordered_map<string, bool> cache;
		
		while (n--) {
			string t; cin >> t;
			cache[t] = true;
		}
		int ans = 0;
		while (m--) {
			string t; cin >> t;
			if (cache[t]) ans++;
		}
		cout << "#" << tt << " " << ans << "\n";
	}
}