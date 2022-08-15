#include <iostream>
#include <queue>
using namespace std;

int n, k;

bool visit[200001] = { false, };

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n>>k;

	queue<int> q; visit[n] = true;
	q.push(n);

	int time = 0;
	while (true) {
		int size = q.size();
		while (size--) {
			int loc = q.front(); q.pop();
			if (loc == k) { cout << time; return 0;}

			int nloc = loc - 1;
			if (nloc >= 0 && !visit[nloc]) {
				q.push(nloc); visit[nloc] = true;
			}
			nloc = loc + 1;
			if (nloc <= 200000 && !visit[nloc]) {
				q.push(nloc); visit[nloc] = true;
			}
			nloc = loc * 2;
			if (nloc <= 200000 && !visit[nloc]) {
				q.push(nloc); visit[nloc] = true;
			}
		}
		time++;
	}
}