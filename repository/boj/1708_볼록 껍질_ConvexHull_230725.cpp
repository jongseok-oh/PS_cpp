#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

int n;

struct Loc{
	int y, x;
}locs[100000];

ll calcDist(const Loc& a, const  Loc& b) {
	ll xx = a.x - b.x, yy = a.y - b.y;
	return xx * xx + yy * yy;
}

ll ccw(const Loc& a,const  Loc& b,const Loc& c) {
	int x1 = b.x - a.x, x2 = c.x - a.x;
	int y1 = b.y - a.y, y2 = c.y - a.y;

	return 1LL * x1 * y2 - 1LL * y1 * x2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int startIdx = -1, startY = 1e9, startX = 1e9;
	for (int i = 0; i < n; i++)
	{
		cin >> locs[i].y >> locs[i].x;
		if (startY > locs[i].y) {
			startY = locs[i].y;
			startX = locs[i].x;
			startIdx = i;
		}
		else if (startY == locs[i].y && startX > locs[i].x) {
			startX = locs[i].x;
			startIdx = i;
		}
	}

	swap(locs[0], locs[startIdx]);

	Loc start = locs[0];
	sort(locs + 1, locs + n, [&start](const Loc& a, const Loc& b) {
		ll ret = ccw(start, a, b);
		if (ret) return ret > 0;
		else return calcDist(start, a) < calcDist(start, b);
	});

	stack<int> dots;
	dots.push(0), dots.push(1);

	for (int i = 2; i < n; i++) {
		while (dots.size()>=2) {
			int first, second;
			second = dots.top(), dots.pop();
			first = dots.top();
			if (ccw(locs[first], locs[second], locs[i]) > 0) {
				dots.push(second);
				break;
			}
		}
		dots.push(i);
	}

	cout << dots.size();
}