#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,a,b,m;

vector<int> edges[101];

bool visit[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>a >> b>>m;
	int t, f;
	while (m--) {
		cin >> t >> f;
		edges[t].push_back(f);
		edges[f].push_back(t);
	}
	queue<int> q; q.push(a);
	visit[a] = true;
	int move = 0;
	while (q.size()) {
		int qsize = q.size();
		while (qsize--) {
			int t = q.front(); q.pop();
			if (t == b) {
				cout << move; return 0;
			}
			for (int& next : edges[t]) {
				if (visit[next]) continue;
				visit[next] = true;
				q.push(next);
			}
		}
		move++;
	}
	cout << -1;
}
