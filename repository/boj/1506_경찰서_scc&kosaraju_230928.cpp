#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int n;

int cost[100];

bool visit[100];
vector<int> con[100];
vector<int> revCon[100];

void dfs(int t, stack<int>& stack) {
	visit[t] = true;
	for (int& nNode : con[t]) 
		if (!visit[nNode])
			dfs(nNode, stack);

	stack.push(t);
}

int getMinCostInScc(int t) {
	visit[t] = true;
	int ret = cost[t];
	for (int& nNode : revCon[t]) {
		if (!visit[nNode]) ret = min(ret, getMinCostInScc(nNode));
	}
	return ret;
}

int kosaraju() {
	stack<int> stack;
	for (int i = 0; i < n; ++i)
		if (!visit[i]) dfs(i, stack);

	int ret = 0;
	memset(visit, 0, n);

	while (stack.size())
	{
		int tNode = stack.top(); stack.pop();

		if (!visit[tNode]) ret += getMinCostInScc(tNode);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> cost[i];

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		char road; cin >> road;
		if (road == '1') {
			con[i].push_back(j);
			revCon[j].push_back(i);
		}
	}

	cout << kosaraju();
}