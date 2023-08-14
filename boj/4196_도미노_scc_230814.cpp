#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int T, N, M;

int order;
vector<int> con[100001];

int pk[100001];
int sccNode[100001];

int sccNodeNum;
int indeg[100001];

int dfs(int tNode, stack<int>& stack) {
	pk[tNode] = ++order;
	stack.push(tNode);

	int parent = pk[tNode];
	for (int& nNode : con[tNode]) {
		if (!pk[nNode]) parent = min(parent, dfs(nNode, stack));
		else if (!sccNode[nNode]) parent = min(parent, pk[nNode]);
	}

	if (parent == pk[tNode]) {

		int tSccNode = ++sccNodeNum;
		while (true)
		{
			int t = stack.top(); stack.pop();
			sccNode[t] = tSccNode;

			if (t == tNode) break;
		}
	}

	return parent;
}

// scc를 정점으로 하는 그래프로 치환
void convert2SccGraph() {

	// 초기화
	order = 0, sccNodeNum = 0;
	
	memset(pk, 0, 4 * (N + 1));
	memset(sccNode, 0, 4 * (N + 1));

	// scc로 분해
	stack<int> stack;
	for (int i = 1; i <= N; i++) if (!sccNode[i]) dfs(i, stack);

	// scc indegree 설정그
	memset(indeg, 0, 4 * (sccNodeNum + 1));

	for (int i = 1; i <= N; i++) {
		for (int& nNode : con[i]) {
			int tSccNode = sccNode[i], nSccNode = sccNode[nNode];
			if (tSccNode != nSccNode) ++indeg[nSccNode];
		}
	}
}

int solve() {
	convert2SccGraph();
	
	// indegree가 0인 개수 return
	int cnt = 0;
	for (int i = 1; i <=sccNodeNum; i++) if (!indeg[i]) cnt++;

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;

		for (int i = 1; i <= N; i++) con[i].clear();

		for (int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;
			con[a].push_back(b);
		}

		cout << solve() << "\n";
	}
}