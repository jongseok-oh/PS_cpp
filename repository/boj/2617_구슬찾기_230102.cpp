#include <iostream>

using namespace std;

int n, m;

bool heavy[100][100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	int a, b;
	while (m--) {
		cin >> a >> b;
		heavy[a][b] = true;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int i = 1; i <= n; i++) {
			if (i == mid) continue;
			for(int j = 1; j <= n; j++) {
				if (j == mid || j == i) continue;
				if (heavy[i][mid] && heavy[mid][j])
					heavy[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int rcnt = 0, ccnt = 0;
		
		for (int j = 1; j <= n; j++) {
			if (heavy[i][j]) rcnt++;
			if (heavy[j][i]) ccnt++;
		}
		if (rcnt > n / 2 || ccnt > n / 2) ans++;
	}
	cout << ans;
}