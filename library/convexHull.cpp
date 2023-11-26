#include <algorithm>
#include <vector>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

int n;

vector<Point> p;

double distance(Point& A, Point& B) {
	ll dx = A.x - B.x, dy = A.y - B.y;
	return sqrt(dx*dx + dy * dy);
}

// 2차원 벡터 외적 -> z 벡터의 크기 반환
ll outer(Point& O, Point& A, Point& B) {
	ll ax = A.x - O.x, ay = A.y - O.y;
	ll bx = B.x - O.x, by = B.y - O.y;

	return ax * by - ay * bx;
}

struct Line {
	Point a;
	Point b;
	Line(Point& a, Point& b) {
		this->a = a; this->b = b;
	}
	double getLen(Point& p) {
		ll op = abs(outer(a, b, p));
		return op / distance(a, b);
	}
};

class ConvexHull {
private:
	vector<Point> convexHull;
	int ccw(Point& O, Point& A, Point& B) {
		ll ret = outer(O, A, B);

		if (ret > 0) return 1;
		else if (!ret) return 0;
		return -1;
	}

	vector<Point> monotoneChain(vector<Point> points) {
		sort(points.begin(), points.end());
		if (points.size() <= 3) return points;
		
		vector<Point> up, down;
		
		for (auto& p : points) {
			while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p) >= 0)
				up.pop_back();
			up.push_back(p);
			while (down.size() >= 2 && ccw(down[down.size() - 2], down[down.size() - 1], p) <= 0)
				down.pop_back();
			down.push_back(p);
		}

		up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);
		return up;
	}
public:
	ConvexHull(vector<Point>& p) {
		convexHull = monotoneChain(p);
	}

	// O(n^2)
	double getMinBreadth() {
		int n = convexHull.size();
		
		double ret = 1e9;
		for (int i = 0; i < n; ++i) {
			Line line = Line(convexHull[i], convexHull[(i + 1)%n]);
			
			double maxLen = -1;
			for (auto& p : convexHull)
				maxLen = max(maxLen, line.getLen(p));

			ret = min(ret, maxLen);
		}

		return ret;
	}
};