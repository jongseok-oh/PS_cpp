#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> failureFunction(const string& s) {
	int n = s.size();
	vector<int> ret(n);

	for (int i = 1, length = 0; i < n; ++i) {
		while (length > 0 && s[i] != s[length]) {
			length = ret[length - 1];
		}
		if (s[i] == s[length]) ++length;
		ret[i] = length;
	}

	return ret;
}

bool kmp(const string& word, const string& pattern) {
	int cnt = 0;
	int n = word.size(), m = pattern.size();
	vector<int> pi = failureFunction(pattern);

	for (int i = 0, length = 0; i < n; ++i) {
		while (length > 0 && word[i] != pattern[length]) {
			length = pi[length - 1];
		}
		if (word[i] == pattern[length]) {
			++length;
			if (length == m) {
				if (++cnt >= 3) return true;
				length = pi[length - 1];
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	
	vector<int> totalFailureFunction = failureFunction(s);
	
	int maxCameleon = totalFailureFunction.back();
	for (; maxCameleon > 0; maxCameleon = totalFailureFunction[maxCameleon -1]) {
		if (kmp(s, s.substr(0, maxCameleon))) break;
	}

	cout << (maxCameleon == 0 ? "-1" : s.substr(0,maxCameleon));
}
