#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int n, m;

int board[1025][1025];

int tree[1500000];

int init(int node, pii start, pii end) {
	if (start == end) return tree[node] = board[start.first][start.second];

	int ydiff1 = (end.first - start.first) / 2,
		ydiff2 = (start.first == end.first ? ydiff1 : ydiff1 + 1),
		xdiff1 = (end.second - start.second) / 2,
		xdiff2 = (start.second == end.second ? xdiff1 : xdiff1 + 1);

	return tree[node] = init(node * 4 - 2, start, { start.first + ydiff1, start.second + xdiff1}) 
		+ (ydiff1 == ydiff2 || xdiff1 == xdiff2?0
		:init(node * 4 - 1, { start.first, start.second + xdiff2 },{ start.first + ydiff1, end.second})
		+ init(node * 4, { start.first + ydiff2, start.second}, {end.first,  start.second + xdiff1}))
		+ init(node * 4 + 1, {start.first + ydiff2, start.second + xdiff2}, end);
}

int W, Y1, X1, Y2, X2;
void Update(int node, pii start, pii end) {
	if (Y1 > end.first || Y1 < start.first || X1 > end.second || X1 < start.second)
		return;
	if (start == end) {
		tree[node] = Y2;
		return;
	}
	int ydiff1 = (end.first - start.first) / 2,
		ydiff2 = (start.first == end.first ? ydiff1 : ydiff1 + 1),
		xdiff1 = (end.second - start.second) / 2,
		xdiff2 = (start.second == end.second ? xdiff1 : xdiff1 + 1);

	Update(node * 4 - 2, start, { start.first + ydiff1, start.second + xdiff1 });
	if (!(ydiff1 == ydiff2 || xdiff1 == xdiff2)) {
		Update(node * 4 - 1, { start.first, start.second + xdiff2 }, { start.first + ydiff1, end.second });
		Update(node * 4, { start.first + ydiff2, start.second }, { end.first,  start.second + xdiff1 });
	}
	Update(node * 4 + 1, { start.first + ydiff2, start.second + xdiff2 }, end);

	tree[node] =
		tree[node * 4 -2] + tree[node * 4 - 1] + tree[node * 4] + tree[node * 4 + 1];
}

int getSum(int node, pii start, pii end) {
	if (Y2 < start.first || Y1 > end.first || X2 < start.second || X1 > end.second)
		return 0;

	if(start.first >= Y1 && start.first <= Y2 && start.second >= X1 && start.second <= X2
		&& end.first >= Y1 && end.first <= Y2 && end.second >= X1 && end.second <= X2)
		return tree[node];

	int ydiff1 = (end.first - start.first) / 2,
		ydiff2 = (start.first == end.first ? ydiff1 : ydiff1 + 1),
		xdiff1 = (end.second - start.second) / 2,
		xdiff2 = (start.second == end.second ? xdiff1 : xdiff1 + 1);

	return getSum(node * 4 - 2, start, { start.first + ydiff1, start.second + xdiff1 })
		+(ydiff1 == ydiff2 || xdiff1 == xdiff2 ? 0
		 :getSum(node * 4 - 1, { start.first, start.second + xdiff2 }, { start.first + ydiff1, end.second })
		+ getSum(node * 4, { start.first + ydiff2, start.second }, { end.first,  start.second + xdiff1 }))
		+ getSum(node * 4 + 1, { start.first + ydiff2, start.second + xdiff2 }, end);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> board[i][j];

	init(1, { 1,1 }, { n,n });

	while (m--)
	{
		cin >> W >> Y1 >> X1 >> Y2;
		if (!W) {
			Update(1, { 1,1 }, { n,n });
		}
		else {
			cin >> X2;
			cout << getSum(1, { 1,1 }, { n,n }) << "\n";
		}
	}
}