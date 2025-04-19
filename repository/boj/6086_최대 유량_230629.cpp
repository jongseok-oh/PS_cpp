#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int capacity[52][52];
int flow[52][52];

int parent[52];

int calc(char c) {
	if (c >= 'A' && c <= 'Z') return c - 'A';
	else return c - 'a' + 26;
}

int maxFlow() {
	
	int ret = 0;
	while (true)
	{
		memset(parent, -1, sizeof(parent));

		parent[0] = 0;
		queue<int> q;
		q.push(0);

		while (q.size()) {
			int t = q.front(); q.pop();

			for (int dir = 0; dir < 52; dir++) {
				if (parent[dir] == -1 && capacity[t][dir] - flow[t][dir] > 0) {
					parent[dir] = t;
					q.push(dir);
				}
			}
		}

		if (parent[25] == -1) return ret;
		int amount = 0x7fffffff;
		
		for (int t = 25; t != 0; t = parent[t])
			amount = min(amount, capacity[parent[t]][t] - flow[parent[t]][t]);

		ret += amount;
		for (int t = 25; t != 0; t = parent[t]) {
			flow[parent[t]][t] += amount;
			flow[t][parent[t]] -= amount;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		char f, t; int cap;
		cin >> f >> t >> cap;
		int fn = calc(f);
		int tn = calc(t);
		capacity[fn][tn] += cap;
		capacity[tn][fn] += cap;
	}

	cout << maxFlow();
}