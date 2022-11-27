#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> con[1000001];
bool visit[1000001];
int dp[1000001][2];

void solve(int t) {
	visit[t] = true;
	dp[t][1] = 1;
	for (int i = 0, len = con[t].size(); i < len; i++) {
		int nnode = con[t][i];
		if (visit[nnode]) continue;
		solve(nnode);
		dp[t][1] +=  min(dp[nnode][0], dp[nnode][1]);
		dp[t][0] += dp[nnode][1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	solve(1);
	cout << min(dp[1][0], dp[1][1]);
}