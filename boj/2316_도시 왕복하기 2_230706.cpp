#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 1e9;

int n, p;

int cap[800][800];
int flow[800][800];
int w[800];

vector<int> con[800];

int level[800];
bool bfs(int start, int end) {
	memset(level, -1, 8 * n);

	level[start] = 0;
	queue<int> q;
	q.push(start);

	while (q.size())
	{
		int t = q.front(); q.pop();
		
		for (int next : con[t]) {
			if (level[next] == -1 && cap[t][next] - flow[t][next] > 0) {
				level[next] = level[t] + 1;
				q.push(next);
				if (next == end) return true;
			}
		}
	}

	return false;
}

bool dfs(int t, int end) {
	if (t == end) return true;
	for (int& i = w[t]; i < con[t].size(); i++) {
		int next = con[t][i];
		if (level[t] + 1 == level[next] && cap[t][next] - flow[t][next] > 0) {
			if (dfs(next, end)) {
				flow[t][next]++;
				flow[next][t]--;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> p;

	for (int i = 2; i < n; i++) {
		int in = i * 2, out = i * 2 + 1;

		cap[in][out] = 1;
		
		con[in].push_back(out);
		con[out].push_back(in);
	}

	for (int i = 0; i < p; i++) {
		int a, b; cin >> a >> b;
		--a; --b;

		int aIn = a * 2, aOut = a * 2 + 1;
		int bIn = b * 2, bOut = b * 2 + 1;

		cap[aOut][bIn] = INF;
		cap[bOut][aIn] = INF;

		con[aOut].push_back(bIn);
		con[bIn].push_back(aOut);

		con[bOut].push_back(aIn);
		con[aIn].push_back(bOut);
	}

	int ans = 0, start = 1, end = 2;
	while (bfs(start, end)){
		memset(w, 0, 8 * n);
		while (true)
		{
			if (!dfs(start, end)) break;
			ans++;
		}
	}
	cout << ans;
}