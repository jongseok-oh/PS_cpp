#include <iostream>
#include <cstring>

using namespace std;

int n, m;

int choose[1000];
bool visit[1000];

int __end[1000];

bool dfs(int start, int idx) {
	for (int i = start; i <= __end[idx]; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		if (choose[i] == -1 || dfs(i + 1,choose[i])) {
			choose[i] = idx;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;

		memset(choose, -1, 4 * n);

		int ans = 0;
		int a;
		for (int i = 0; i < m; i++) {
			cin >> a >> __end[i];
			a--; __end[i]--;
			
			memset(visit, 0, n);
			if (dfs(a,i)) ans++;
		}
		cout << ans << "\n";
	}
}