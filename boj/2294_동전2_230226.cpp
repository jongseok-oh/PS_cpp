#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

int coin[100];
bool visit[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin>>coin[i];
	
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (coin[i] <= k) {
			q.push(coin[i]); visit[coin[i]] = true;
		}
	}
	int ans = 1;
	while (q.size()) {
		int qsize = q.size();
		while (qsize--) {
			int t = q.front(); q.pop();
			if (t == k) {
				cout << ans; return 0;
			}
			for (int i = 0; i < n; i++) {
				int ncoin = coin[i] + t;
				if (ncoin <= k && !visit[ncoin]) {
					visit[ncoin] = true;
					q.push(ncoin);
				}
			}
		}
		ans++;
	}
	cout << -1;
}