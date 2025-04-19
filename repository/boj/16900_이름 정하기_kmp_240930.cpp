#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;

vector<int> failureFunction(const string& s) {
	int n = s.size();
	vector<int> ret(n);

	for (int i = 1; i < n; ++i) {
		int length = ret[i - 1];
		while (length > 0 && s[i] != s[length]) {
			length = ret[length - 1];
		}
		if (s[i] == s[length]) length++;
		ret[i] = length;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; int k;
	cin >> s>>k;
	vector<int> pi = failureFunction(s);
	
	ll n = s.size();
	ll sharedLength = pi.back();
	
	cout << k * n - sharedLength * (k - 1);
}
