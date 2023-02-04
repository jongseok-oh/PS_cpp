#include <iostream>

using namespace std;

int n,m;

bool edges[200][200];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		cin >> edges[i][j];
		if (i == j) edges[i][j] = true;
	}

	for (int cent = 0; cent < n; cent++)
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++)
					edges[i][j] = edges[i][j] || (edges[i][cent] && edges[cent][j]);

	int from = -1, to;
	while (m--) {
		cin >> to;
		to--;
		if (from != -1 && !edges[from][to]) {
			cout << "NO"; return 0;
		}
		from = to;
	}
	cout << "YES";
}
