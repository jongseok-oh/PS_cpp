#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

int visit[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int ans = 1;

	queue<int> q;
	q.push(1);
	
	visit[1] = ans;

	while (q.size()) {
		int num = q.front(); q.pop();

		if (num == n) {
			cout << visit[num] - 1<< "\n";
			break;
		}
		
		for (int nNum : { num * 3, num * 2, num + 1 }) {
			if (nNum <= n && !visit[nNum]) {
				visit[nNum] = visit[num] + 1;
				q.push(nNum);
			}
		}
	}
	while (true)
	{
		cout << n << " ";
		if (n == 1) break;
		if (n % 3 == 0 && visit[n] == visit[n/3] + 1) {
			n /= 3;
		}
		else if (n % 2 == 0 && visit[n] == visit[n / 2] + 1) {
			n /= 2;
		}
		else n--;
	}
}