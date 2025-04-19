#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


pll loc[4];

int ccw(int f, int s, int t) {
	ll ret = (loc[s].first - loc[f].first) * (loc[t].second - loc[f].second)
		- (loc[t].first - loc[f].first) * (loc[s].second - loc[f].second);

	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; i++) cin >> loc[i].first >> loc[i].second;
	int L1L2 = ccw(0, 1, 2) * ccw(0, 1, 3);
	int L2L1 = ccw(2, 3, 0) * ccw(2, 3, 1);
	
	if (!L1L2 && !L2L1) {
		if (loc[0] > loc[1]) swap(loc[0], loc[1]);
		if(loc[2] > loc[3]) swap(loc[2], loc[3]);

		cout << (loc[1] >= loc[2] && loc[0] <= loc[3]);
	}
	else cout << (L1L2 <=0 && L2L1 <= 0);
}