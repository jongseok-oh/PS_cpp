#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;

vector<int> todo[1001];
int selected[1001];
bool visit[1001];

bool dfs(int t) {
	for (int i = 0, len = todo[t].size(); i < len; i++) {
		int work = todo[t][i];
		if (visit[work]) continue;
		visit[work] = true;
		if (!selected[work] || dfs(selected[work]))
		{
			selected[work] = t;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	
	for (int i = 1; i <=n; i++) {
		int len; cin >> len;
		while (len--) {
			int work; cin >> work;
			todo[i].push_back(work);
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) ans++;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!k) break;
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) {
			ans++; k--;
		}
	}
	cout << ans;
}