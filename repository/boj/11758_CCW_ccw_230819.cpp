#include <iostream>

using namespace std;

struct Loc{
	int y, x;
}dots[3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 3; i++) cin >> dots[i].y >> dots[i].x;

	int y1 = dots[0].y - dots[1].y, x1 = dots[0].x - dots[1].x;
	
	int y2 = dots[2].y - dots[1].y, x2 = dots[2].x - dots[1].x;

	int ccw = x1 * y2 - y1 * x2;

	int ans = 0;
	if (ccw > 0) ans = 1;
	else if (ccw < 0) ans = -1;

	cout << ans;
}