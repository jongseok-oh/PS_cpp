#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct shark {
	int m, s, i;
};

shark sharks[51];
vector<int> ss[51];
bool visit[51];
int choose[51];

bool cmp(const shark& a, const shark& b) {
	if (a.m == b.m) {
		if (a.s == b.s)
			return a.i > b.i;
		return a.s > b.s;
	}
	return a.m > b.m;
}

bool dfs(int t) {
	
	for (int i = 0, len = ss[t].size(); i < len; i++) {
		int ssr = ss[t][i];
		if (visit[ssr])continue;
		visit[ssr] = true;
		if (!choose[ssr] || dfs(choose[ssr])) {
			choose[ssr] = t;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> sharks[i].m >> sharks[i].s >> sharks[i].i;
	
	sort(sharks + 1, sharks + n + 1, cmp);

	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			if (sharks[i].m >= sharks[j].m
				&& sharks[i].s >= sharks[j].s
				&& sharks[i].i >= sharks[j].i) ss[i].push_back(j);
	
	int ans = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= n; i++) {
			memset(visit, 0, n + 1);
			if (dfs(i)) ans++;
		}
	}
	cout << n - ans;
}