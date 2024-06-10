#include <iostream>
#include <algorithm>
#include <unordered_set>

typedef long long ll;

using namespace std;

int n;
string strs[10];
ll startHash[10][100000], poww[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int _max = 1e9;
	for (int i = 0; i < n; ++i) {
		cin >> strs[i];
		_max = min(_max, (int)strs[i].size());
	}

	int prime = 31;
	poww[0] = 1;
	for (int i = 1; i < _max; ++i) poww[i] = poww[i - 1] * prime;

	for (int i = 0; i < n; ++i){
		startHash[i][0] = strs[i][0];
		for (int j = 1; j < _max; ++j) {
			startHash[i][j] = startHash[i][j-1] * prime + strs[i][j];
		}
	}

	int low = 0, high = _max + 1;
	while (low + 1 < high) {
		int mid = (low + high) >> 1;
		
		unordered_set<ll> prev, temp;
		for (int i = 0; i < n; ++i) {
			temp.clear();
			
			ll hash = startHash[i][mid-1], tPow = poww[mid-1];
			if (i == 0 || prev.count(hash))
				temp.insert(hash);
			
			for (int j = mid; j < _max; ++j) {
				hash -= tPow * strs[i][j - mid];
				hash *= prime;
				hash += strs[i][j];

				if (i == 0 || prev.count(hash))
					temp.insert(hash);
			}
			prev.swap(temp);
		}
		
		if (prev.size()) low = mid;
		else high = mid;
	}
	cout<<low;
}