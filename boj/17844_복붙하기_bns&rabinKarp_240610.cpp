#include <iostream>
#include <unordered_map>

using namespace std;

// colision ㄱ-;
bool check(int len, const string& s) {
	unordered_map<int, int> cache, cache1;
	int n = s.size();
	int prime = 31, hash = 0, pov = 1;
	int prime1 = 37, hash1 = 0, pov1 = 1;

	for (int i = 0; i < len; ++i) {
		hash *= prime;
		hash += s[i];
		hash1 *= prime1;
		hash1 += s[i];
		
		if (i) {
			pov *= prime;
			pov1 *= prime1;
		}
	}
	cache[hash] = len - 1;
	cache1[hash1] = len - 1;

	for (int i = len; i < n; ++i) {
		hash -= pov * s[i - len];
		hash *= prime;
		hash += s[i];

		hash1 -= pov1 * s[i - len];
		hash1 *= prime1;
		hash1 += s[i];

		if (cache.count(hash) && cache1.count(hash1)) {
			if (cache[hash] < i - len + 1)
				return true;
		}
		else {
			cache[hash] = i;
			cache1[hash1] = i;
		}
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