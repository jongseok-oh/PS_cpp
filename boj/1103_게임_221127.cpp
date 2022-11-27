#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;

string map[50];
bool visit[50][50];
int dp[50][50];

int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

int solve(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m || map[r][c] == 'H') { return 0; }
	if (visit[r][c]) {
		cout << -1; exit(0);
	}
	int& ret = dp[r][c];

	if (ret != -1) return ret;

	visit[r][c] = true;
	int move = map[r][c] - '0';

	for (int dir = 0; dir < 4; dir++) {
		int ny = r + dy[dir] * move,
			nx = c + dx[dir] * move;
		ret = max(ret, 1 + solve(ny, nx));
	}
	visit[r][c] = false;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	memset(dp, -1, sizeof(dp));
	cout<<solve(0, 0);
}