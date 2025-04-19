#include <iostream>
using namespace std;

int n;

bool win[2001][2001];

bool visit[2001];

int p[2001];

int dp[2001];

int dfs(int t) {

	int& ret = dp[t];
	if (ret) return ret;

	ret = 1;

	for (int i = 1; i <= n; i++) {
		if (win[t][i] && !visit[i]) {
			visit[i] = true;
			int len = dfs(i) + 1;
			if (len > ret) {
				p[t] = i;
				ret = len;
			}
			visit[i] = false;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> win[i][j];

	visit[1] = true;
	cout << dfs(1) << "\n";
	cout << 1 << " ";
	int t = 1;
	while (p[t]) {
		cout << p[t] << " ";
		t = p[t];
	}
}