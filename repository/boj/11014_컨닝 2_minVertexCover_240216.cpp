#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int C,N,M,n,m;

struct Loc { int y, x; };

vector<Loc> odd, even;
vector<int> con[3200];

int oMatch[3200];

bool visit[3200];
bool dfs(int e) {
	if (visit[e]) return false;
	visit[e] = true;

	for (int o : con[e]) {
		if (oMatch[o] == -1 || dfs(oMatch[o])) {
			oMatch[o] = e;
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> C;

	while (C--) {
		cin >> N >> M;
		char tt;
		odd.clear(); even.clear();
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
			cin >> tt;
			if (tt == '.') {
				if (j & 1) odd.push_back({ i,j });
				else even.push_back({ i,j });
			}
		}
		n = even.size(), m = odd.size();
		for (int i = 0; i < n; ++i) con[i].clear();

		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			auto[ey, ex] = even[i];
			auto[oy, ox] = odd[j];

			if (abs(ey - oy) <= 1 && abs(ex - ox) <= 1) con[i].push_back(j);
		}

		memset(oMatch, -1, 4*m);

		int ret = n + m;
		for (int i = 0; i < n; ++i) {
			memset(visit, 0, n);
			if (dfs(i)) --ret;
		}
		cout << ret << "\n";
	}
}