#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

int orderQ[100000];

int qsize, fq;

int parent[18][100001];

int n;

priority_queue<int> child[100001];

int depth[100001];

void initOrder(int t) {
	orderQ[qsize++] = t;
	
	while (fq != qsize) {
		int tt = orderQ[fq++];
		
		while (child[tt].size())
		{
			int next = -child[tt].top(); child[tt].pop();
			orderQ[qsize++] = next;
			depth[next] = depth[tt] + 1;
		}
	}
}

ll getLen(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	ll ret = 0;

	int diff = depth[a] - depth[b];
	if (diff) {
		for (int i = 17; i >= 0; i--) {
			if (diff >= (1 << i)) {
				diff -= (1 << i);
				ret += (1 << i);
				a = parent[i][a];
			}
		}
	}
	
	if (a == b) return ret;

	for (int i = 17; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			ret += (1 << i) * 2;
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return ret + 2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		qsize = 0, fq = 0;
		cin >> n;

		memset(parent, 0, sizeof(parent));

		for (int i = 2; i <= n; i++) {
			int p; cin >> p;
			parent[0][i] = p;
			child[p].push(-i);
		}
		initOrder(1);
		
		for (int i = 1; i < 18; i++) {
			for (int j = 2; j <= n; j++) {
				if (parent[i - 1][j]) parent[i][j] = parent[i - 1][parent[i - 1][j]];
			}
		}

		ll ans = 0;
		for (int i = 0; i < qsize - 1; i++) {
			ans += getLen(orderQ[i], orderQ[i + 1]);
		}
		cout << "#" << tt << " " << ans << "\n";
	}
	return 0;
}