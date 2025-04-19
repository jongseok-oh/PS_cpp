#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

int n;

Point points[100000];

Point calVector(Point& from, Point& to) {
	return { to.first - from.first, to.second - from.second };
}

ll ccw(Point& O, Point& A, Point& B) {
	Point OA = calVector(O, A);
	Point OB = calVector(O, B);

	return OA.first * OB.second - OA.second * OB.first;
}

int monotoneChain() {
	vector<Point> up, down;

	for (int i = 0; i < n; ++i) {
		while (up.size() >= 2
			&& ccw(up[up.size() - 2], up[up.size() - 1], points[i]) >= 0)
			up.pop_back();
		up.push_back(points[i]);

		while (down.size() >= 2
			&& ccw(down[down.size() - 2], down[down.size() - 1], points[i]) <= 0)
			down.pop_back();
		down.push_back(points[i]);
	}

	return up.size() + down.size() - 2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	if (n == 3) { cout << 3; return 0; }

	for (int i = 0; i < n; ++i)
		cin >> points[i].first >> points[i].second;

	sort(points, points + n);

	cout << monotoneChain();
}