#include <iostream>
#include <queue>

using namespace std;

int n,m;

vector<int> edges[1001];
int ingrid[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m;

	while (m--) {
		int len; cin >> len;
		int parent; cin >> parent;
		for (int i = 1; i < len; i++) {
			int t; cin >> t;
			ingrid[t]++;
			edges[parent].push_back(t);
			parent = t;
		}
	}
	queue<int> q;

	for (int i = 1; i <= n; i++) if (!ingrid[i]) q.push(i);

	vector<int> ans;
	while (q.size()) {
		int t = q.front(); q.pop();

		ans.push_back(t);

		for (int i = 0; i < edges[t].size(); i++) {
			int next = edges[t][i];
			ingrid[next]--;
			if (!ingrid[next]) q.push(next);
		}
	}

	if (ans.size() != n) { cout << 0; return 0;}

	for (int& i : ans) cout << i << "\n";
}