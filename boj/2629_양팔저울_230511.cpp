#include <iostream>
#include <vector>

using namespace std;

int n,m;

bool weight[40001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	weight[0] = true;
	while (n--) {
		int bid; cin >> bid;
		vector<int> cache;
		for (int i = 0; i < 40001; i++) {
			if (weight[i]) {
				int a = abs(i - bid);
				int b = i + bid;

				cache.push_back(a);
				if (b < 40001) cache.push_back(b);
			}
		}
		for (int t : cache) weight[t] = true;
	}
	cin >> m;
	while (m--) {
		int chk; cin >> chk;
		cout << (weight[chk] ? 'Y' : 'N') << " ";
	}
}