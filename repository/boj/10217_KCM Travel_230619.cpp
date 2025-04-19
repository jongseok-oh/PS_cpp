#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100][10001];

int T, n, m, k;

struct Ticket { int v, c, d; };
vector<Ticket> tickets[100];

int solve(int money, int node) {
	if (node == n - 1) return 0;

	int& ret = dp[node][money];
	
	if (ret) return ret;

	ret = 1e9;

	for (auto& Ticket : tickets[node])
		if (money >= Ticket.c)
			ret = min(ret, solve(money - Ticket.c, Ticket.v) + Ticket.d);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		u--; v--;
		tickets[u].push_back({ v,c,d });
	}

	int ans = solve(m, 0);
	if (ans == 1e9)cout << "Poor KCM";
	else cout << ans;
}