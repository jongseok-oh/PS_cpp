#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int n, k;

bool visit[200001][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	visit[n][0] = true;
	priority_queue<pii> q;
	q.push({0,n});
	while (q.size()) {
		pii t = q.top(); q.pop();
		int time = -t.first,
			loc = t.second;
		if (loc == k) {
			cout << time; return 0;
		}
		if (loc * 2 <= 200000 && !visit[loc * 2][1]) {
			visit[loc * 2][1] = true;
			q.push({-time , loc * 2 });
		}
		for (int next : {loc - 1, loc + 1}) {
			if (next >= 0 && next <= 200000 && !visit[next][0]) {
				visit[next][0] = true;
				q.push({ -(time + 1),next});
			}
		}
		
	}
}