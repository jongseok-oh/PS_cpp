#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> edge[1000001];

// i번 노드가 얼리어답터일 때, 아닐 때
// i번 노드 하위 트리의 최소 얼리 어답터 수
int dp[1000001][2];
bool visit[1000001];

void dfs(int t) {

	visit[t] = true;
	dp[t][0] = 1;

	for (int& next : edge[t]) {
		if (visit[next]) continue;
		dfs(next);

		dp[t][0] += min(dp[next][0], dp[next][1]);
		dp[t][1] += dp[next][0];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}