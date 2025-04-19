#include <iostream>
#include <vector>

using namespace std;

const int _MAX = 1000000;

int n;

struct Loc { int y, x; };
vector<int> line[1000];

int unused = 0;
Loc edge[_MAX];
int edgeCnt[_MAX];

int makeEdge(int y, int x, int cnt) {
	edge[unused].y = y;
	edge[unused].x = x;
	edgeCnt[unused++] = cnt;

	return unused - 1;
}

void dfs(int t) {
	while (!line[t].empty()) {
		int idx = line[t].back();
		if (!edgeCnt[idx]) line[t].pop_back();
		else {
			edgeCnt[idx]--;
			int y = edge[idx].y;
			int x = edge[idx].x;

			if (y == t) dfs(x);
			else dfs(y);
		}
	}
	cout << t + 1 << " ";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int start = -1;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			sum += num;
			if (j < i || !num) continue;

			start = i;

			int idx = makeEdge(i, j, num);

			line[i].push_back(idx);
			line[j].push_back(idx);
		}
		if (sum & 1) {
			cout << -1; return 0;
		}
	}

	dfs(start);
}