#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, l, m;

pii fish[100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l >> m;

	for (int i = 0; i < m; i++)
		cin >> fish[i].first >> fish[i].second;

	vector<pii> rect;

	int row = 1;
	while (true) {
		int col = (l - row * 2) / 2;
		if (col <= 0) break;
		rect.push_back({ row,col });
		row++;
	}


	int _max = -1;
	for (int i = 0; i < m; i++) {
		int ly = fish[i].first,
			lx = fish[i].second;

		for (int j = 0; j < rect.size(); j++) {
			
			int r = rect[j].first,
				c = rect[j].second;

			for (int rr = 0; rr <= r; rr++) {
				int ty = ly - rr;
				if (ty < 1) break;
				for (int cc = 0; cc <= c; cc++) {
					int tx = lx - cc;
					if (tx < 1) break;
					
					int ey = min(ty + r, n);
					int ex = min(tx + c, n);

					int cnt = 0;
					for (int fi = 0; fi < m; fi++) {
						int fy = fish[fi].first,
							fx = fish[fi].second;

						if (fy >= ty && fy <= ey && fx >= tx && fx <= ex) cnt++;
					}
					_max = max(_max, cnt);
				}
			}
		}
	}
	cout << _max;
}