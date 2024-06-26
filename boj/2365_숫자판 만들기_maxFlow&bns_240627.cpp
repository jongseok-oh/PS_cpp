#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, s = 100, t = 101, diff = 50;
int originCap[102][102];

vector<int> con[102];
void addEdge(int from, int to, int cap) {
	originCap[from][to] = cap;
	con[from].push_back(to);
	con[to].push_back(from);
}

int cap[102][102];
void init(int mid) {
	memcpy(cap, originCap, sizeof cap);
	for (int i = 0; i < n; ++i) for (int j = diff; j < diff + n; ++j)
		cap[i][j] = mid;
}

int level[102];
bool bfs() {
	memset(level, -1, sizeof level);
	queue<int> q; q.push(s);
	level[s] = 0;

	while (q.size()) {
		int node = q.front(); q.pop();
		for (int next : con[node]) {
			if (cap[node][next] > 0 && level[next] == -1) {
				level[next] = level[node] + 1;
				q.push(next);
			}
		}
	}
	return level[t] != -1;
}

int iter[102];
int dfs(int v, int f) {
	if (v == t) return f;
	for (int next : con[v]) {
		int& tcap = cap[v][next];
		if (tcap > 0 && level[v] < level[next]) {
			int d = dfs(next, min(f, tcap));
			if (d > 0) {
				tcap -= d;
				cap[next][v] += d;
				return d;
			}
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	while (bfs()) {
		memset(iter, 0, sizeof iter);
		while (int f = dfs(s, 1e9))
			flow += f;
	}
	return flow;
}

bool chk(int mid, int totSum) {
	init(mid);
	return totSum == dinic();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int sum, rsum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> sum; rsum += sum;
		addEdge(s, i, sum);
	}
	for (int i = diff; i < diff + n; ++i) {
		cin >> sum;
		addEdge(i, t, sum);
	}

	for (int i = 0; i < n; ++i) for (int j = diff; j < diff + n; ++j)
		addEdge(i, j, 0);

	int low = -1, high = 10000;
	while (low + 1 < high) {
		int mid = (low + high) >> 1;
		if (chk(mid, rsum)) high = mid;
		else low = mid;
	}
	cout << high << "\n";

	chk(high, rsum);

	for (int i = 0; i < n; ++i) {
		for (int j = diff; j < diff + n; ++j) {
			cout << high - cap[i][j] << " ";
		}
		cout << "\n";
	}
}
