#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;

struct integer
{
	ll a, c, b;
};

integer ints[20000];

ll chk(ll tar) {
	ll cnt = 0;

	for (int i = 0; i < n; i++) {
		ll start = max(tar, ints[i].a);
		ll end = (ints[i].c - ints[i].a) / ints[i].b * ints[i].b + ints[i].a;
		if (end < tar) continue;
		cnt += (end - start) / ints[i].b + 1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> ints[i].a >> ints[i].c >> ints[i].b;
	
	long long low = 0, high = 0x7fffffffLL + 1;

	while (low + 1 < high) {
		long long mid = (low + high) >> 1;
		ll cnt = chk(mid);
		if (cnt&1) low = mid;
		else high = mid;
	}
	if (low) {
		cout << low << " " << chk(low) - chk(low + 1);
	}
	else cout << "NOTHING";
}