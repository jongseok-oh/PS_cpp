#include <iostream>
#include <cstring>
using namespace std;

int cache[100001];
int g, p;

int getP(int t) {
	if (cache[t] == -1) return t;
	return cache[t] = getP(cache[t]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> g >> p;
	
	memset(cache, -1, 4 * (g + 1));

	int cnt = 0;
	for (int i = 0; i < p; i++) {
		int plain; cin >> plain;
		int p = getP(plain);
		if (!p) {
			cout << cnt; return 0;
		}
		cache[p] = p - 1;
		cnt++;
	}
	cout << cnt;
}