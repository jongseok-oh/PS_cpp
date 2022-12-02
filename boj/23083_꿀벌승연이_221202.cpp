#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;

int mod = 1e9 + 7;

bool holes[1001][1001];
int dp[1001][1001];

int ody[] = { -1,0,1 }, odx[] = { 1,1,0 };
int edy[] = { 0,1,1 }, edx[] = { 1,1,0 };


int solve(int y, int x) {
	if (y == n && x == m) return 1;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;
	int* dy; int* dx;
	if (x & 1) {
		dy = ody; dx = odx;
	}
	else {
		dy = edy; dx = edx;
	}

	for (int dir = 0; dir < 3; dir++) {
		int ny = y + dy[dir],
			nx = x + dx[dir];

		if (ny <1 || ny > n || nx <1 || nx >m || holes[ny][nx]) continue;
		ret += solve(ny, nx);
		ret %= mod;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	
	int y, x;
	while (k--) {
		cin >> y >> x;
		holes[y][x] = true;
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1);
}