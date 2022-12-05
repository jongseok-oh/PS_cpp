#include <iostream>
#include <queue>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	priority_queue<int> q;
	int x;
	while (n--) {
		cin >> x;
		if (!x) {
			if (q.empty()) cout << "0\n";
			else {
				cout << -q.top() << "\n";
				q.pop();
			}
		}
		else q.push(-x);
	}
}