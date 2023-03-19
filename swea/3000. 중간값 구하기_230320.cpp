#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n, A; cin >> n >> A;
		priority_queue<int> left;
		priority_queue<int, vector<int>, greater<int>> right;
		left.push(A);
		int ans = 0;
		int a, b;
		while (n--) {
			cin >> a >> b;
			left.top() < a? right.push(a):left.push(a);
			left.top() < b? right.push(b):left.push(b);

			if (left.size() > right.size() + 1) {
				while (left.size() != right.size() + 1)
				{
					right.push(left.top());
					left.pop();
				}
			}
			else if (left.size() <= right.size()) {
				while (left.size() <= right.size())
				{
					left.push(right.top());
					right.pop();
				}
			}

			ans += left.top();
			ans %= 20171109;
		}
		cout << "#" << tt << " " << ans << "\n";
	}
}