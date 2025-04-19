#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

vector<int> edges[100001];
int parent[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	queue<int> q;
	parent[1] = 1;
	q.push(1);

	while (q.size())
	{
		int t = q.front(); q.pop();

		for (int next : edges[t]) {
			if (!parent[next]) {
				parent[next] = t;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";
}