#include <iostream>
#include <string>

using namespace std;

int n, m;
string str, pattern;

int pi[1000000];

int ans[1000000];
int ansCnt = 0;

void make_pi() {

	int j = 0;
	for (int i = 1; i < m; i++) {

		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];

		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}
}

void kmp() {
	make_pi();

	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && str[i] != pattern[j])
			j = pi[j - 1];

		if (str[i] == pattern[j]) {
			if (j == m - 1) {
				ans[ansCnt++] = i - m + 1;
				j = pi[j];
			}
			else j++;
		}
	}
}

int main() {
	getline(cin, str);
	getline(cin, pattern);
	n = str.size();
	m = pattern.size();

	kmp();

	cout << ansCnt << "\n";
	for (int i = 0; i < ansCnt; i++) cout << ans[i] + 1 << " ";
}