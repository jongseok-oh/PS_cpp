#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;

vector<int> r[1001];

int selected[1001];

bool visit[1001];

bool dfs(int t) {
	for (int i = 0, len = r[t].size(); i < len; i++) {
		int rr = r[t][i];
		if (visit[rr]) continue;
		visit[rr] = true;
		if (!selected[rr] || dfs(selected[rr])) {
			selected[rr] = t;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >>m;
	for (int i = 1; i <= n; i++) {
		int len; cin >> len;
		while (len--) {
			int rr; cin >> rr;
			r[i].push_back(rr);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) ans++;
	}
	cout << ans;
}