#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int v, e, order;

int pk[10001];
bool visit[10001];

vector<int> con[10001];

int dfs(int tNode, stack<int>& stack, vector<vector<int>>& sccs) {

	stack.push(tNode);

	int p = pk[tNode] = ++order;

	for (int& nNode : con[tNode]) {
		if (!pk[nNode]) p = min(p, dfs(nNode, stack, sccs));
		else if (!visit[nNode]) p = min(p, pk[nNode]);
	}
	
	if (p == pk[tNode]) {
		vector<int> scc;
		while (true) {
			int t = stack.top(); stack.pop();

			scc.push_back(t);
			visit[t] = true;

			if (t == tNode) break;
		}

		sort(scc.begin(), scc.end());
		sccs.push_back(scc);
	}

	return p;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b; cin >> a >> b;
		con[a].push_back(b);
	}

	vector<vector<int>> sccs;
	stack<int> stack;

	for (int i = 1; i <= v; i++)
		if (!visit[i]) dfs(i, stack, sccs);

	cout << sccs.size() << "\n";

	sort(sccs.begin(), sccs.end(), [](const auto& a, const auto& b) {
		return a[0] < b[0];
	});

	for (auto& scc : sccs) {
		for (int& node : scc) cout << node << " ";
		cout << -1 << "\n";
	}
}