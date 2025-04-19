#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;

pii nbook[1000];
bool used[1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			nbook[i] = {b, a};
		}

		sort(nbook, nbook + m);

		int ans = 0;
		for (int i = 0; i < m; i++) {
			int e = nbook[i].first,
				s = nbook[i].second;
			for (int j = s; j <= e; j++) {
				if (!used[j]) {
					used[j] = true;
					ans++; break;
				}
			}
		}

		cout << ans << "\n";
		memset(used, 0, n + 1);
	}
}