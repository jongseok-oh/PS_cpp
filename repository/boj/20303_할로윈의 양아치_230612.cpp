#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, m, k;

int parent[30001];
int candies[30001];

int getP(int t) {
	if (parent[t] < 0) return t;
	return parent[t] = getP(parent[t]);
}

void merge(int a, int b) {
	int aP = getP(a);
	int bP = getP(b);

	if (aP == bP) return;

	parent[aP] += parent[bP];
	parent[bP] = aP;

	candies[aP] += candies[bP];
}

struct children {
	int candy, cnt;
};

int dp[3000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) cin >> candies[i];

	memset(parent, -1, sizeof(parent));

	while (m--)
	{
		int a, b; cin >> a >> b;
		merge(a, b);
	}

	vector<children> bag;

	for (int i = 1; i <= n; i++) 
		if (parent[i] < 0) bag.push_back({ candies[i], -parent[i] });


	int bagSize = bag.size();

	for (int i = 0; i < bagSize; i++) for (int j = k - 2; j >= 0; j--) {
		if (bag[i].cnt + j < k)
			dp[bag[i].cnt + j] = max(dp[bag[i].cnt + j], bag[i].candy + dp[j]);
	}

	cout << dp[k - 1];
}