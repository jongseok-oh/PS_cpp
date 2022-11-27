#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int crain[50];
int ccnt[50];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> crain[i];
	sort(crain, crain + n);
	cin >> m;
	for (int i = 0; i < m; i++){
		int box; cin >> box;
		int j = 0;
		while (j<n && crain[j] < box)j++;
		if (j == n) {
			cout << -1; return 0;
		}
		ccnt[j]++;
	}
	
	int time = 0, scrain = 0;
	while (true) {
		
		bool move = false;
		for (int i = scrain; i < n; i++) {
			int t = i;
			while (t >= 0 && !ccnt[t]) t--;

			if (t == -1) {
				scrain = i + 1;
				continue;
			}
			ccnt[t]--;
			move = true;
		}
		if(move) time++;
		if (scrain == n) break;
	}
	cout << time;
}