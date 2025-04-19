#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, m, a,b,c;

vector<pii> road[4001];

int foxDist[4001];
double wolfDist[4001][2];

struct foxInfo
{
	int cost, node;

	bool operator < (foxInfo tf)const {
		return this->cost > tf.cost;
	}
};

struct wolfInfo
{
	double cost;
	int node, flag;

	bool operator < (wolfInfo tw)const {
		return this->cost > tw.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	while (m--) {
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		foxDist[i] = 1e9;
		wolfDist[i][0] = 1e9;
		wolfDist[i][1] = 1e9;
	}

	priority_queue<foxInfo> q;
	foxDist[1] = 0;
	q.push({ 0,1 });
	while (q.size()) {
		foxInfo t = q.top(); q.pop();
		if (t.cost > foxDist[t.node]) continue;
		for (auto& next : road[t.node]) {
			int nNode = next.first,
				cost = next.second;
			
			if (foxDist[nNode] > t.cost + cost) {
				foxDist[nNode] = t.cost + cost;
				q.push({ foxDist[nNode], nNode });
			}
		}
	}
	priority_queue<wolfInfo> wq;
	wolfDist[1][0] = 0;
	wq.push({ 0,1,0 });
	while (wq.size()) {
		wolfInfo t = wq.top(); wq.pop();
		if (t.cost > wolfDist[t.node][t.flag]) continue;
		int tflag = t.flag ^ 1;
		for (auto& next : road[t.node]) {
			int nNode = next.first;
			double cost = (tflag?(double)next.second/2:next.second*2);

			if (wolfDist[nNode][tflag] > t.cost + cost) {
				wolfDist[nNode][tflag] = t.cost + cost;
				wq.push({ wolfDist[nNode][tflag], nNode, tflag});
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (foxDist[i] < min(wolfDist[i][0], wolfDist[i][1])) ans++;
	}
	cout << ans;
}