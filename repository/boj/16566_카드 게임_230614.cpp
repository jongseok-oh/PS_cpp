#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

int cards[4000000];
int parent[4000000];

int getP(int t) {
	if (!parent[t]) return t;
	return parent[t] = getP(parent[t]);
}

void merge(int a, int b) {
	if (a == m - 1) return;

	int bP = getP(b);

	parent[a] = bP;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) cin >> cards[i];

	sort(cards, cards + m);

	while (k--) {
		int tar; cin >> tar;

		int low = -1, high = m;
		while (low + 1 < high)
		{
			int mid = (low + high) >> 1;

			if (cards[mid] > tar) high = mid;
			else low = mid;
		}
		int idx = getP(high);
		cout << cards[idx] << "\n";
		merge(idx, idx + 1);
	}
}