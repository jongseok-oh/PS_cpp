#include <iostream>
#include <cstring>

using namespace std;

int T, n, a, b, tar1, tar2;

int parent[10001];

int dfs(int t) {
	int p = parent[t];
	parent[t] = -1;
	if (!p || p == -1) return t;
	return dfs(p);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < n-1; i++) {
			cin >> a >> b;
			parent[b] = a;
		}
		cin >> tar1 >> tar2;
		dfs(tar1);
		cout << dfs(tar2)<<"\n";
	}
}