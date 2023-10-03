#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

vector<int> con[2050];

int convertNum(int t) {
	if (t < 0) return -t * 2;
	else return t * 2 - 1;
}

int order;
int pk[2050];

int sccNum;
int sccNums[2050];

stack<int> st;
int dfs(int tNode) {
	st.push(tNode);

	int p = pk[tNode] = order++;

	for (int& nNode : con[tNode]) {
		if (!pk[nNode]) p = min(p, dfs(nNode));
		else if (!sccNums[nNode]) p = min(p, pk[nNode]);
	}

	if (p == pk[tNode]) {
		while (true) {
			int t = st.top(); st.pop();
			sccNums[t] = sccNum;
			if (t == tNode) break;
		}
		++sccNum;
	}

	return p;
}

bool solve() {
	order = 1;
	memset(pk, 0, sizeof pk);

	sccNum = 1;
	memset(sccNums, 0, sizeof sccNums);

	for (int i = 1; i <= 2 * n; ++i)
		if (!sccNums[i]) dfs(i);

	// 노의심 검사
	for (int i = 1; i <= n; ++i)
		if (sccNums[i * 2 - 1] == sccNums[i * 2]) return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m) {
		for (int i = 1; i <= 2 * n; ++i)
			con[i].clear();

		// 상근이 필 true
		con[convertNum(-1)].push_back(convertNum(1));

		int a, b;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			con[convertNum(-a)].push_back(convertNum(b));
			con[convertNum(-b)].push_back(convertNum(a));
		}

		cout << (solve() ? "yes\n" : "no\n");
	}
}