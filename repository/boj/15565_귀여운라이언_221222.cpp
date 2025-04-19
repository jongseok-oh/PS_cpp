#include <iostream>
#include <algorithm>

using namespace std;

int n,k;

int toy[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>k;

	for (int i = 0; i < n; i++) cin >> toy[i];

	int low = 0, high = -1;

	int _min = 0x7fffffff;

	int tcnt = 0;
	while (high < n) {
		if (tcnt < k) {
			high++;
			tcnt += toy[high] & 1;
		}
		else {
			_min = min(_min, high - low + 1);
			tcnt -= toy[low++]&1;
		}
	}
	cout << (_min == 0x7fffffff ? -1 : _min);
}