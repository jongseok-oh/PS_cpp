#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;

vector<int> con[100000];

int order;
int pk[100000];
bool finish[100000];

int sccNum;
int sccNums[100000];
vector<vector<int>> sccs;

int dfs(int tNode, stack<int>& stack) {
	stack.push(tNode);

	int p = pk[tNode] = order++;

	for (int& nNode : con[tNode]) {
		if (!pk[nNode]) p = min(p, dfs(nNode, stack));
		else if (!finish[nNode]) p = min(p, pk[nNode]);
	}

	if (p == pk[tNode]) {
		vector<int> scc;
		while (true) {
			int t = stack.top(); stack.pop();

			finish[t] = true;
			scc.push_back(t);
			sccNums[t] = sccNum;

			if (t == tNode) break;
		}
		sccs.push_back(scc);
		++sccNum;
	}

	return p;
}

void makeSccs() {
	order = 1;
	memset(pk, 0, 4 * n);
	memset(finish, 0, n);

	sccNum = 0;
	memset(sccNums, 0, 4 * n);
	sccs.clear();
	
	stack<int> stack;

	for (int i = 0; i < n; ++i)
		if (!finish[i]) dfs(i, stack);
}

int indegree[100000];
void solve() {
	makeSccs();
	int sccsSize = sccs.size();
	memset(indegree, 0, 4 * sccsSize);

	for (int i = 0; i < sccsSize; ++i) {
		for (int& tNode : sccs[i]) {
			for (int& nNode : con[tNode]) {
				if (sccNums[tNode] != sccNums[nNode])
					indegree[sccNums[nNode]]++;
			}
		}
	}

	int idx = -1;

	for (int i = 0; i < sccsSize; ++i) {
		if (!indegree[i]) {
			if (idx != -1) {
				cout << "Confused\n\n"; return;
			}
			idx = i;
		}
	}

	sort(sccs[idx].begin(), sccs[idx].end());

	for (int& node : sccs[idx]) cout << node << "\n";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) con[i].clear();
		
		int a, b;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			con[a].push_back(b);
		}
		solve();
	}
}