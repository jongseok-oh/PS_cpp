#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n, m;

pii nbook[1001];
int choose[1001];
bool visit[1001];

bool dfs(int t) {
	int s = nbook[t].first,
		e = nbook[t].second;

	for (int i = s; i <= e; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		if (!choose[i] || dfs(choose[i])) {
			choose[i] = t;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;

		for (int i = 1; i <= m; i++) {
			int a, b; cin >> a >> b;
			nbook[i] = { a,b };
		}
		
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			memset(visit, 0,sizeof(visit));
			if (dfs(i)) ans++;
		}
		cout << ans << "\n";
		memset(choose, 0, sizeof(choose));
	}
}