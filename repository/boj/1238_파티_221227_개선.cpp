#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m, x;

vector<pii> road[1001], rv[1001];

int d1[1001], d2[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;

	int a, b, c;
	while (m--)
	{
		cin >> a >> b >>c;
		road[a].push_back({ b,c });
		rv[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) d1[i] = d2[i] = 0x7fffffff;
	d1[x] = d2[x] = 0;
	
	priority_queue<pii> q;
	q.push({ 0,x });

	// 1~n까지 다익을 다돌리는게 아니라
	// 역방향 도로를 저장해 x에서 들어오는 것
	// x에서 나가는 것들에 대해서만 다익을 돌려
	// 오고 나갈 때 최대값을 구해 줌

	while (q.size()) {
		pii t = q.top(); q.pop();
		int cost = -t.first,
			node = t.second;
		if (d1[node] < cost) continue;
		for (pii& nn : road[node])
			if (d1[nn.first] > nn.second + cost) {
				d1[nn.first] = nn.second + cost;
				q.push({ -d1[nn.first], nn.first });
			}
	}
	q.push({ 0,x });
	while (q.size()) {
		pii t = q.top(); q.pop();
		int cost = -t.first,
			node = t.second;
		if (d2[node] < cost) continue;
		for (pii& nn : rv[node])
			if (d2[nn.first] > nn.second + cost) {
				d2[nn.first] = nn.second + cost;
				q.push({ -d2[nn.first], nn.first });
			}
	}

	int _max = -1;
	for (int i = 1; i <= n; i++)
		_max = max(_max, d1[i] + d2[i]);
	cout << _max;
}