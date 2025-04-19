#include <iostream>

using namespace std;

int n;
char rl[1000000];
char tar[1000000];

int pi[1000000];

void make_pi() {
	int begin = 1, match = 0;
	while (begin + match < n) {
		if (rl[begin + match] == rl[match]) {
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

int calcCnt() {
	int begin = 0, match = 0, cnt = 0;
	while (begin < n)
	{
		if (tar[(begin + match) % n] == rl[match]) {
			++match;
			if (match == n) cnt++;
		}
		else {
			if (!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	return cnt;
}

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> rl[i];
	for (int i = 0; i < n; i++) cin >> tar[i];
	make_pi();
	
	int cnt = calcCnt();
	int _gcd = gcd(n, cnt);

	cout << (cnt / _gcd) << '/' << (n / _gcd);
}