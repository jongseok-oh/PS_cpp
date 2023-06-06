#include <iostream>
#include <algorithm>

using namespace std;

int n;

int idx[1000001];
int cards[100001];
int score[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	int _max = -1;
	for (int i = 1; i <=n; i++)
	{
		cin >> cards[i];
		idx[cards[i]] = i;
		_max = max(_max, cards[i]);
	}

	for (int i = 1; i < _max; i++) {
		if (!idx[i]) continue;

		for (int j = i + i; j <= _max; j += i) {
			if (idx[j]) {
				score[idx[i]]++;
				score[idx[j]]--;
			}
		}
	}

	for (int i = 1; i <= n; i++) cout << score[i] << " ";
}