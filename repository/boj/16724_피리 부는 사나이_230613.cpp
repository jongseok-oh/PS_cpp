#include <iostream>

using namespace std;

int n, m;

int dy[26], dx[26];

char map[1000][1000];
int visit[1000][1000];

int temp = 1;

bool dfs(int y, int x) {
	if (visit[y][x]) {
		return visit[y][x] == temp;
	}
	visit[y][x] = temp;
	return dfs(y + dy[map[y][x] - 'A'], x + dx[map[y][x] - 'A']);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dy['D' - 'A'] = 1; dx['D' - 'A'] = 0;
	dy['R' - 'A'] = 0; dx['R' - 'A'] = 1;
	dy['U' - 'A'] = -1; dx['U' - 'A'] = 0;
	dy['L' - 'A'] = 0; dx['L' - 'A'] = -1;

	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> map[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (!visit[i][j]) {
			if (dfs(i, j)) ans++;
			temp++;
		}
	}

	cout << ans;
}