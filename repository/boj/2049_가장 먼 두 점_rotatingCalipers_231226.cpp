#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second
typedef pair<int, int> pii;

int n;
vector<pii> locs;

pii operator - (const pii& A,const pii& B) {
    return { A.x - B.x, A.y - B.y };
}

int ccw(const pii& O, const pii& A, const pii& B) {
    pii OA = A - O;
    pii OB = B - O;
    return OA.x * OB.y - OA.y * OB.x;
}

vector<pii> convexHull() {
    sort(locs.begin(), locs.end());
    if (locs.size() < 3) {
        sort(locs.begin() + 1, locs.end(), [&](auto& a, auto& b) {
            return ccw(locs[0], a, b) > 0;
            });
        return locs;
    }

    vector<pii> up, down;
    for (pii& loc : locs) {
        while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], loc) >= 0)
            up.pop_back();
        up.push_back(loc);
        while (down.size() >= 2 && ccw(down[down.size() - 2], down[down.size() - 1], loc) <= 0)
            down.pop_back();
        down.push_back(loc);
    }
    up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);
    return up;
}

int calcDist(pii& A, pii& B) {
    int xx = A.x - B.x, yy = A.y - B.y;
    return xx * xx + yy * yy;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    locs.resize(n);
    for (auto& loc : locs) cin >> loc.x >> loc.y;

    auto ch = convexHull();

    int chn = ch.size();
    int ret = 0;

    // 두 벡터의 방향만 보면 됨으로
    // 둘 다 원점 벡터로 옮겨서 ccw
    pii origin = { 0,0 };
    for (int i = 0, j = 1; i < chn; ++i) {
        while (ccw(origin, ch[(i + 1) % chn] - ch[i], ch[(j+1) % chn] - ch[j]) < 0)
            j = (j + 1) % chn;

        int dist = calcDist(ch[i], ch[j]);
        if (ret < dist) ret = dist;
    }
    cout << ret;
}