#include <iostream>
#include <vector>

using namespace std;

vector<int> net[101];

int q[150];
bool visit[101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;

	while (m--) {
		int a, b; cin >> a >> b;
		net[a].push_back(b);
		net[b].push_back(a);
	}

	int qCnt = 0, front = 0;

	q[qCnt++] = 1;
	visit[1] = true;

	int ans = -1;
	while (qCnt != front) {
		int num = q[front++];
		ans++;

		for (int& next : net[num]) {
			if (visit[next]) continue;
			visit[next] = true;
			
			q[qCnt++] = next;
		}
	}
	cout << ans;
}