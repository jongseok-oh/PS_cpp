#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n, k;

int moveCnt[100501];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	moveCnt[n] = 1;
	bool find = false;
	int move = 0;
	while (q.size()) {
		int qsize = q.size();
		set<int> store;
		while (qsize--) {
			int t = q.front(); q.pop();
			
			if (t == k) {
				find = true;
				break;
			}

			if (t - 1 >= 0) {
				if (!moveCnt[t - 1]) {
					store.insert(t-1);
					moveCnt[t - 1] += moveCnt[t];
				}
				else {
					if (store.find(t - 1) != store.end()) {
						moveCnt[t - 1] += moveCnt[t];
					}
				}
			}

			if (t +1 <= k) {
				if (!moveCnt[t + 1]) {
					store.insert(t + 1);
					moveCnt[t + 1] += moveCnt[t];
				}
				else {
					if (store.find(t + 1) != store.end()) {
						moveCnt[t + 1] += moveCnt[t];
					}
				}
			}

			if (t * 2 < 100501) {
				if (!moveCnt[t * 2]) {
					store.insert(t * 2);
					moveCnt[t * 2] += moveCnt[t];
				}
				else {
					if (store.find(t * 2) != store.end()) {
						moveCnt[t * 2] += moveCnt[t];
					}
				}
			}
		}
		if (find) break;
		for (auto it = store.begin(); it != store.end(); it++) {
			q.push(*it);
		}
		move++;
	}

	cout << move << "\n" << moveCnt[k];
}