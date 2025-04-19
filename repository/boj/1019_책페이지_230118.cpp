#include <iostream>

using namespace std;

int n;

long long ans[10];

void Add(int n, int tSq) {
	while (n) {
		ans[n % 10] += tSq;
		n /= 10;
	}
}

void solve(int a, int b, int tSq) {
	
	while (a <= b && a % 10) {
		Add(a, tSq);
		a++;
	}
	if (a > b) return;
	while (a <= b && b % 10 != 9) {
		Add(b, tSq);
		b--;
	}
	int len = (b / 10 - a / 10 + 1) * tSq;
	for (int i = 0; i < 10; i++) ans[i] += len;
	solve(a / 10, b / 10, tSq * 10);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	solve(1, n, 1);
	for (int i = 0; i < 10; i++) cout << ans[i] << " ";
}