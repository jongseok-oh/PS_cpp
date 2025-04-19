#include <iostream>
#include <string>

using namespace std;

string s;

int l;
int pi[1000000];

void make_pi() {
	
	int j = 0;
	for (int i = 1; i < l; i++) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			pi[i] = ++j;
	}
}

int main() {
	
	cin >> l >>s;
	make_pi();

	cout << l - pi[l-1];
}