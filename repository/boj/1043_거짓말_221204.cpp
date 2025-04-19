#include <iostream>
#include <vector>

using namespace std;
int n,m;

int trueCnt;
bool trueMan[51];

vector<int> party[50];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> trueCnt;
	int idx;
	for (int i = 0; i < trueCnt; i++) {
		cin >> idx;
		trueMan[idx] = true;
	}
	
	int pcnt, p;
	for (int i = 0; i < m; i++) {
		cin >> pcnt;
		for (int j = 0; j < pcnt; j++) {
			cin >> p;
			party[i].push_back(p);
		}
	}

	int mcnt = m;
	while (mcnt--) {
		for (int i = 0; i < m; i++) {
			bool trueManHere = false;
			for (int j = 0, len = party[i].size(); j < len; j++) {
				if (trueMan[party[i][j]]) {
					trueManHere = true; break;
				}
			}
			if (trueManHere) {
				for (int j = 0, len = party[i].size(); j < len; j++) {
					trueMan[party[i][j]] = true;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool trueManHere = false;
		for (int j = 0, len = party[i].size(); j < len; j++) {
			if (trueMan[party[i][j]]) {
				trueManHere = true;
				break;
			}
		}
		if (!trueManHere) ans++;
	}
	cout << ans;
}