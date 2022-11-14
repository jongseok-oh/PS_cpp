#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int k,v,e;

int colors[20001];

vector<int> con[20001];

bool bfs(int tt) {
	queue<int> q;
	q.push(tt);
	colors[tt] = 0;
	while (q.size()) {
		int t = q.front(); q.pop();
		int tcolor = colors[t];
		
		for (int i = 0, len = con[t].size(); i < len; i++) {
			int nnode = con[t][i];
			if (colors[nnode] == -1) {
				q.push(nnode);
				colors[nnode] = tcolor ^ 1;
			}
			else {
				if (colors[nnode] == tcolor) return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> k;
	while (k--) {
		cin >> v >> e;
		int a, b;
		memset(colors, -1, 4 * (v + 1));
		while (e--) {
			cin >> a >> b;
			con[a].push_back(b);
			con[b].push_back(a);
		}
		bool flag = true;
		for (int i = 1; i <= v; i++) {
			if (colors[i] == -1) {
				if (!bfs(i)) {
					flag = false;
					cout << "NO\n"; break;
				}
			}
		}
		if (flag) cout << "YES\n";
		for (int i = 1; i <= v; i++) con[i].clear();
	}
}