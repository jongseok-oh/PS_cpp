#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, m;

vector<int> con[20050];

int convertNum(int t) {
	if (t < 0) return (-t - 1) * 2 + 1;
	else return (t-1)* 2;
}

int order = 1;
int pk[20050];
bool finish[20050];

int sccNum = 0;
int sccNums[20050];

int dfs(int tNode, stack<int>& stack) {
	stack.push(tNode);

	int p = pk[tNode] = order++;
	for (int& nNode : con[tNode]) {
		if (!pk[nNode]) p = min(p, dfs(nNode, stack));
		else if (!finish[nNode]) p = min(p, pk[nNode]);
	}

	if (p == pk[tNode]) {
		while (true) {
			int t = stack.top(); stack.pop();
			
			finish[t] = true;
			sccNums[t] = sccNum;
			if (t == tNode) break;
		}
		++sccNum;
	}

	return p;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	int a, b;
	while (m--)
	{
		cin >> a >> b;
		con[convertNum(-a)].push_back(convertNum(b));
		con[convertNum(-b)].push_back(convertNum(a));
	}

	stack<int> stack;
	for (int i = 0; i < n * 2; ++i)
		if (!finish[i]) dfs(i, stack);

	for(int i = 0; i<n; i++)
		if (sccNums[i * 2] == sccNums[i * 2 + 1]) {
			cout << 0; return 0;
		}

	cout << 1;
}