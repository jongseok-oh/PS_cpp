#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

string str;
int n;
int pi[1000000];

void make_pi() {
	n = str.size();
	memset(pi, 0, n * 4);

	int begin = 1, match = 0;
	while (begin + match < n) {
		if (str[begin + match] == str[match]) {
			++match;
			pi[begin + match - 1] = match;
		}
		else {
			if (!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while (true) {
		cin >> str;
		if (str == ".") return 0;

		make_pi();

		// 약수 생성
		vector<int> div;
		for (int i = 1; i <= (int)sqrt(n); i++) {
			if (n % i == 0){
				div.push_back(i);
				if (i * i != n) div.push_back(n / i);
			}
		}

		sort(div.begin(), div.end());

		bool find = false;
		for (auto it = div.begin(); it != div.end(); it++) {
			if (n - pi[n - 1] == *it) {
				find = true;
				cout << n / (*it) << "\n"; break;
			}
		}
		if (!find) cout << 1 << "\n";
	}
}