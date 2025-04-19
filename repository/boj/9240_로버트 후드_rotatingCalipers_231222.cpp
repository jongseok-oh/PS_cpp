#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<int, int> pii;
#define x first
#define y second

int c;
vector<pii> locs;

int ccw(const pii& O,const pii& A,const pii& B){
	int x1 = A.x - O.x, y1 = A.y - O.y;
	int x2 = B.x - O.x, y2 = B.y - O.y;
	return x1 * y2 - y1 * x2;
}

double calcDist(pii& A, pii& B){
	int xx = A.x - B.x , yy = A.y - B.y;
	return sqrt(xx * xx + yy* yy);
}

pii operator - (const pii& A,const pii& B){
	return {A.x - B.x, A.y - B.y};
}

vector<pii> convexHull(){
	sort(locs.begin(), locs.end());
	
	if(c <= 3){
		// 그라함 스캔 안쓰고 모노톤 체인 쓰면
		// 아래의 로직이 필요하다.
		// 로테이팅 캘리퍼스 로직에서 볼록껍질 점들의 순서가 시계 방향이라고 가정하고 함
		// 따라서 입력 점이 3이하일 때 0번 점 기준 시계 방향 정렬 필요
		sort(locs.begin()+1, locs.end(), [&](auto& a, auto& b){
			return ccw(locs[0], a, b) <= 0;
		});
		return locs;
	}

	vector<pii> up, down;

	for(pii& loc: locs){
		while(up.size()>=2 && ccw(up[up.size()-2], up[up.size()-1], loc) >= 0)
			up.pop_back();
		up.push_back(loc);
		while(down.size()>=2 && ccw(down[down.size()-2], down[down.size()-1], loc) <= 0)
			down.pop_back();
		down.push_back(loc);
	}
	up.insert(up.end(), down.rbegin() + 1, down.rend() -1);

	return up;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed; cout.precision(7);
	cin>>c;
	locs.resize(c);
	for(int i = 0; i<c; ++i) cin>>locs[i].x>>locs[i].y;

	auto up = convexHull();
	int n = up.size();
	double ret = calcDist(up[0], up[1]);
	for(int i = 0, j =1; i<n; ++i){
		while(ccw(up[i], up[(i+1)%n], up[(j+1)%n] - (up[j] - up[i]) ) < 0)
			j = (j + 1)%n;
		double tDist = calcDist(up[i], up[j]);
		if(tDist > ret) ret = tDist;
	}
	cout<<ret;
}