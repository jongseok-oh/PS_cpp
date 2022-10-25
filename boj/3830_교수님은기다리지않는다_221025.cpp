#include <iostream>
#include <cstring>

using namespace std;

int parent[100001];
long long wdiff[100001];

int getp(int t) {
	if (!parent[t]) return t;

	int tp = parent[t];
	int np = getp(tp);
	wdiff[t] += wdiff[tp];
	return parent[t] = np;
}

void Union(int a, int b, int w) {
	int ap = getp(a);
	int bp = getp(b);

	if (ap == bp) return;

	wdiff[bp] = wdiff[a] - wdiff[b] + w;
	parent[bp] = ap;
}

void question(int a, int b) {
	int ap = getp(a);
	int bp = getp(b);

	if (ap != bp) cout<<"UNKNOWN\n";
	else {
		cout << wdiff[b] - wdiff[a] << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true)
	{
		int n, m;
		cin >> n >> m;
		if (!n && !m) break;
		
		memset(parent, 0, 4 * (n + 1));
		memset(wdiff, 0, 8 * (n + 1));

		while (m--) {
			char cmd;
			int a, b;
			cin >> cmd >> a >> b;

			if (cmd == '!') {
				int w;
				cin >> w;
				Union(a, b, w);
			}
			else question(a, b);
		}
	}
}