#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string s;

int pi[5000];

int ans = 0;

void make_pi(string sub) {
	int n = sub.size();

	memset(pi, 0, sizeof(pi));

	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && sub[i] != sub[j])
			j = pi[j - 1];
		
		if (sub[i] == sub[j])
		{
			pi[i] = ++j;
			ans = max(ans, pi[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	
	for (int i = 0, len = s.size(); i < len; i++) {
		make_pi(s.substr(i));
	}
	cout << ans;
}