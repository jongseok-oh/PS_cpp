#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii dots[4];

int ccw(pii& p1, pii& p2, pii& p3) {
	ll ret = ((ll)p2.first - p1.first) * ((ll)p3.second - p1.second)
		- ((ll)p3.first - p1.first) * ((ll)p2.second - p1.second);

	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

void find_intersection(pii& p0, pii& p1, pii& p2, pii& p3) {
	// Ax + By = E
	// Cx + Dy = F
	double A = (double)p1.second - p0.second;
	double B = (double)p0.first - p1.first;
	double E = A * p0.first + B * p0.second;
	double C = (double)p3.second - p2.second;
	double D = (double)p2.first - p3.first;
	double F = C * p2.first + D * p2.second;

	double det = A * D - B * C;

	if (det == 0) {
		cout << "1\n";
		if (p1 == p2 && p3 >= p1) cout << p1.first << " " << p1.second;
		else if (p0 == p3 && p1 >= p2) cout << p0.first << " " << p0.second;
	}
	else {
		cout << fixed; cout.precision(9);
		double x = (D * E - B * F) / det;
		double y = (A * F - C * E) / det;
		cout << "1\n" << x << " " << y;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < 4; i++) cin >> dots[i].first >> dots[i].second;

	int L1L2 = ccw(dots[0], dots[1], dots[2]) * ccw(dots[0], dots[1], dots[3]);
	int L2L1 = ccw(dots[2], dots[3], dots[0]) * ccw(dots[2], dots[3], dots[1]);

	if (!L1L2 && !L2L1) {
		if (dots[0] > dots[1]) swap(dots[0], dots[1]);
		if(dots[2] > dots[3]) swap(dots[2], dots[3]);
		if (dots[0] <= dots[3] && dots[1] >= dots[2]) {
			find_intersection(dots[0], dots[1], dots[2], dots[3]);
		}
		else cout << 0;
	}
	else {
		if (L1L2 <=0 && L2L1 <= 0) {
			find_intersection(dots[0], dots[1], dots[2], dots[3]);
		}
		else {
			cout << 0;
		}
	}
}