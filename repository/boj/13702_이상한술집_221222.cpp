#include <iostream>

using namespace std;

int n,k;

int mak[10000];

int chk(int tar) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) cnt += mak[i] / tar;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	long long _max = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> mak[i];
		_max = _max < mak[i] ? mak[i] : _max;
	}

	long long low = 0, high = _max + 1;
	
	while (low + 1 < high) {
		long long mid = (low + high) >> 1;
		
		long long cnt = chk(mid);

		if (cnt < k) high = mid;
		else low = mid;
	}
	cout << low;
}