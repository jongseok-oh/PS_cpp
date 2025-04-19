#include <iostream>
#include <queue>

using namespace std;

int n,m,k;

int ans[1001];
int cnt[1001];

struct Node {
	int cost, node;

	bool operator <(const Node& a) const {
		return cost > a.cost;
	}
};

vector<Node> road[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m>>k;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		road[a].push_back({ c,b });
	}

	priority_queue<Node> q;

	q.push({ 0,1 });

	while (q.size()) {
		Node t = q.top(); q.pop();
		
		if (cnt[t.node] == k) continue;
		
		ans[t.node] = t.cost;
		cnt[t.node]++;
		
		for (const Node& next : road[t.node]) {
			int nNode = next.node;
			int nCost = next.cost;

			q.push({ t.cost + nCost, nNode });
		}
	}

	for (int i = 1; i <= n; i++) cout << (cnt[i] == k ? ans[i] : -1) << "\n";
}