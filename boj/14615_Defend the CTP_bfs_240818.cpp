#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;

vector<bool> bfs(int start, vector<vector<int>>& con) {
	vector<bool> visit(n+1);
	queue<int> q;
	visit[start] = true;
	q.push(start);

	while (q.size()) {
		int t = q.front(); q.pop();
		for (int next : con[t]) {
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return visit;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);	
	cin >> n >> m;
	
	vector<vector<int>> con(n + 1);
	vector<vector<int>> revcon(n + 1);

	int a, b;
	while (m--) {
		cin >> a >> b;
		con[a].push_back(b);
		revcon[b].push_back(a);
	}
	vector<bool> visit = bfs(1, con);
	vector<bool> revVisit = bfs(n, revcon);

	int T, boom; cin >> T;
	while (T--) {
		cin >> boom;
		if (visit[boom] && revVisit[boom]) {
			cout << "Defend the CTP\n";
		}
		else cout << "Destroyed the CTP\n";
	}
};
