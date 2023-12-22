#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;

int T, n;
vector<pii> locs;

ll getDist(const pii& A, const pii& B){
	ll xx = A.x - B.x, yy = A.y - B.y;
	return xx * xx + yy*yy;
}

pii operator -(const pii& A, const pii& B){
	return {A.x - B.x, A.y - B.y};
}

int ccw(const pii& O, const pii& A,const pii& B){
	pii OA = A - O;
	pii OB = B- O;
	ll ret = (ll)OA.x * OB.y - (ll)OA.y * OB.x;
	if(ret > 0) return 1;
	else if(ret < 0) return -1;
	return 0;
}

vector<pii> convexHull(){
	sort(locs.begin(), locs.end());
	vector<pii> up, down;

	if(locs.size() <= 3) return locs;

	for(pii& loc: locs){
		while(up.size() >= 2 && ccw(up[up.size() -2], up[up.size() -1], loc) >= 0)
			up.pop_back();
		up.push_back(loc);
		while(down.size() >= 2 && ccw(down[down.size() -2], down[down.size() -1], loc) <= 0)
			down.pop_back();
		down.push_back(loc);
	}

	up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);
	return up;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>T;
	while (T--)
	{
		cin>>n;
		locs.resize(n);
		for(pii& loc: locs) cin>>loc.x>>loc.y;
		if(n == 2){
			cout<<locs[0].x<<" "<<locs[0].y<<" "<<locs[1].x<<" "<<locs[1].y<<"\n";
			continue;
		}

		// convex hull 시계 방향으로 반환
		// down에 up 넣으면(반시계 순서) ccw 체크 반대로 갈겨야됨
		vector<pii> ch = convexHull();
		int chn = ch.size();

		// rotating calipers
		int idx1 = 0, idx2 = 1; // convex hull(엄밀히 말하면 아님)이 직선인 경우 대비
		ll maxDist = 0;
		for(int i = 0, j = 1; i<chn; ++i){
			// 현재 기준 벡터와 평행을 넘어설 때 까지
			while(ccw(ch[i], ch[(i+1)%chn], ch[(j+1)%chn]-(ch[j%chn] - ch[i])) < 0)
				j++;

			ll tDist = getDist(ch[i], ch[j%chn]);
			if(tDist > maxDist){
				maxDist = tDist;
				idx1 = i; idx2 = j%chn;
			}
		}
		cout<<ch[idx1].x<<" "<<ch[idx1].y<<" "<<ch[idx2].x<<" "<<ch[idx2].y<<"\n";
	}
}