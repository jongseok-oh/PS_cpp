#include <iostream>

using namespace std;

typedef long long ll;

int n, r,g,b;

ll dp[10][101][101][101];
ll facto[11];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> r >> g >> b;

	if (r > 0) dp[0][r - 1][g][b] = 1;
	if (g > 0) dp[0][r][g-1][b] = 1;
	if (b > 0) dp[0][r][g][b-1] = 1;

	facto[1] = 1;
	for (int i = 2; i < 11; i++) facto[i] = facto[i - 1] * i;

	for (int level = 1; level < n; level++) {
		for(int red = 0; red<=r; red++)
			for (int green = 0; green <= g; green++)
				for (int blue = 0; blue <= b; blue++) {
					if (!dp[level-1][red][green][blue]) continue;
					
					if ((level + 1) % 2 == 0) {
						int half = (level + 1) / 2;
						
						if (red >= half && green >= half)
							dp[level][red - half][green - half][blue]
							+= dp[level - 1][red][green][blue]
							* facto[level + 1] / facto[half] / facto[half];

						if (red >= half && blue >= half)
							dp[level][red - half][green][blue - half]
							+= dp[level - 1][red][green][blue]
							* facto[level + 1] / facto[half] / facto[half];

						if (green >= half && blue >= half)
							dp[level][red][green - half][blue - half]
							+= dp[level - 1][red][green][blue]
							* facto[level + 1] / facto[half] / facto[half];
					}

					if ((level + 1) % 3 == 0) {
						int third = (level + 1) / 3;

						if (red >= third && green >= third && blue >= third)
							dp[level][red - third][green - third][blue - third]
							+= dp[level - 1][red][green][blue]
							* facto[level + 1] / facto[third] / facto[third] / facto[third];
					}

					if (red >= level + 1)
						dp[level][red - (level + 1)][green][blue]
						+= dp[level - 1][red][green][blue];

					if (green >= level + 1)
						dp[level][red ][green - (level + 1)][blue]
						+= dp[level - 1][red][green][blue];

					if (blue >= level + 1)
						dp[level][red][green][blue - (level + 1)]
						+= dp[level - 1][red][green][blue];
				}
	}

	ll ans = 0;

	for (int red = 0; red <= r; red++)
		for (int green = 0; green <= g; green++)
			for (int blue = 0; blue <= b; blue++)
				ans += dp[n - 1][red][green][blue];

	cout << ans;
}