#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n;

pii city[16];

double dist[16][16];

double dp[16][1<<16];

double solve(int t, int visit) {
	visit |= 1<<t;
	double& ret = dp[t][visit];
	if (ret != 0) return ret;
	if (visit == ((1 << n) - 1)) return dist[t][0];
	ret = 1e9;

	for (int i = 0; i < n; i++) {
		if (visit & (1 << i)) continue;
		ret = min(ret, solve(i, visit) + dist[t][i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> city[i].first >> city[i].second;

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		if (i == j) continue;
		dist[i][j] = sqrt((city[i].first - city[j].first) * (city[i].first - city[j].first)
			+ (city[i].second - city[j].second) * (city[i].second - city[j].second));
	}
	
	cout.precision(20);
	cout << solve(0, 0);
}