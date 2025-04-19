#include <iostream>
#include <unordered_map>

using namespace std;

// 64bit를 써서 colision 내성 up
typedef long long ll;
// 전역으로 사용
// 아마 clear가 resize 크기를 되돌리지는 않는 듯
unordered_map<ll, int> cache;

bool check(int len, const string& s) {
	cache.clear();

	int prime = 31, n = s.size();
	ll hash = 0, pov = 1;

	for (int i = 0; i < len; ++i) {
		hash *= prime;
		hash += s[i];
		pov *= i ? prime : 1;
	}
	cache[hash] = len - 1;

	for (int i = len; i < n; ++i) {
		hash -= pov * s[i - len];
		hash *= prime;
		hash += s[i];

		if (cache.count(hash)) {
			if (cache[hash] < i - len + 1)
				return true;
		}
		else cache[hash] = i;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;

	int low = 0, high = s.size() / 2 + 1;
	while (low + 1 < high) {
		int mid = (low + high) >> 1;
		if (check(mid, s)) {
			low = mid;
		}
		else high = mid;
	}
	cout << (low == 0 ? -1 : low);
}