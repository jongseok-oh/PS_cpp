#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

int con[500][500];
int flow[500][500];

int parent[500];

int mf(int s, int t) {
	int ret = 0;

	while (true) {
		memset(parent, -1, 4 * n);
		queue<int> q;
		parent[s] = s;
		q.push(s);

		while (q.size()) {
			int tt = q.front(); q.pop();
			
			for (int i = 0; i < n; i++) {
				if (parent[i] == -1 && con[tt][i] - flow[tt][i] > 0) {
					parent[i] = tt;
					q.push(i);
				}
			}
		}

		if (parent[t] == -1) break;

		int amount = 0x7fffffff;
		for (int p = t; p != s; p = parent[p])
			amount = min(amount, con[parent[p]][p] - flow[parent[p]][p]);

		ret += amount;

		for (int p = t; p != s; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		--a; --b;

		con[a][b] += c;
		con[b][a] += c;
	}
	int s, t; cin >> s >> t;
	--s; --t;
	cout << mf(s, t);
}