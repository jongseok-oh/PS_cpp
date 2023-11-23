#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	int x, y, idx;
}points[2000];

int c, n;

int ccw(const Point& O, const Point& A, const Point& B) {
	int ay = A.y - O.y, ax = A.x - O.x;
	int by = B.y - O.y, bx = B.x - O.x;

	return ax * by - ay * bx;
}

int dist(const Point& O, const Point& A) {
	return abs(O.y - A.y) + abs(O.x - A.x);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> c;

	while (c--) {
		cin >> n;
		int _min = -1;
		for (int i = 0; i < n; ++i) {
			points[i].idx = i;
			cin >> points[i].x >> points[i].y;

			int ty = points[i].y, tx = points[i].x;

			if (_min == -1 || (ty == points[_min].y && tx < points[_min].x) || ty < points[_min].y)
				_min = i;
		}

		swap(points[0], points[_min]);

		// 좌측 하단 점 기준 ccw sort
		sort(points + 1, points + n, [&](auto& a, auto& b) {
			int _ccw = ccw(points[0], a, b);
			if (_ccw) return _ccw > 0;
			return dist(points[0], a) < dist(points[0], b);
		});

		// 마지막 직선 재배치
		int pt = n - 1;
		while (!ccw(points[0], points[pt], points[pt - 1])) pt--;

		reverse(points + pt, points + n);

		for (int i = 0; i < n; ++i) cout << points[i].idx << " "; cout << "\n";
	}
}