#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k;

vector<int> con[501];

int bMatch[501];

bool visit[501];
bool dfs(int a) {
	if (visit[a]) return false;
	visit[a] = true;

	for (int b : con[a]) {
		if (!bMatch[b] || dfs(bMatch[b])) {
			bMatch[b] = a;
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;

	int a, b;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		con[a].push_back(b);
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		memset(visit, 0, sizeof visit);
		if (dfs(i)) ret++;
	}
	cout << ret;
}