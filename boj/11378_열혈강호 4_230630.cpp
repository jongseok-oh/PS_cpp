#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int DIFF = 1000, source = 2001, dest = 2002, bp = 2003;

int n, m,k;

int con[2004][2004];
int flow[2004][2004];
int parent[2004];

vector<int> edge[2004];

int mf() {
	int ret = 0;
	while (true)
	{
		memset(parent, -1, sizeof(parent));

		queue<int> q;
		parent[source] = source;
		q.push(source);

		while (q.size()) {
			int t = q.front(); q.pop();
			for (int& next : edge[t]) {
				if (parent[next] == -1 && con[t][next] - flow[t][next] > 0) {
					parent[next] = t;
					q.push(next);
				}
			}
		}

		if (parent[dest] == -1) break;

		int cnt = 0x7fffffff;
		for (int p = dest; p != source; p = parent[p])
			cnt = min(cnt, con[parent[p]][p] - flow[parent[p]][p]);

		ret += cnt;
		for (int p = dest; p != source; p = parent[p]) {
			flow[parent[p]][p] += cnt;
			flow[p][parent[p]] -= cnt;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m>>k;

	// source -> 벌점
	edge[source].push_back(bp);
	edge[bp].push_back(source);
	con[source][bp] = k;

	for (int i = 1; i <=n; i++) {
		// source -> 직원
		edge[source].push_back(i);
		edge[i].push_back(source);
		con[source][i] = 1;

		// 벌점 -> 직원
		edge[bp].push_back(i);
		edge[i].push_back(bp);
		con[bp][i] = k;

		int len; cin >> len;
		for (int j = 0; j < len; j++) {
			int work; cin >> work; work += DIFF;

			// 직원 -> 일
			edge[i].push_back(work);
			edge[work].push_back(i);
			con[i][work] = 1;

			// 일 -> dest
			edge[work].push_back(dest);
			edge[dest].push_back(work);
			con[work][dest] = 1;
		}
	}

	cout << mf();
}