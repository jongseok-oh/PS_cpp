#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> pii;

int n, l;
vector<pii> locs;

pii operator -(const pii& A, const  pii& B) {
    return { A.x - B.x, A.y - B.y };
}

int ccw(const pii& O, const pii& A, const pii& B) {
    pii OA = A - O, OB = A - B;
    return OA.x * OB.y - OA.y * OB.x;
}

double dist(pii& A, pii& B) {
    int xx = A.x - B.x, yy = A.y - B.y;
    return sqrt(xx * xx + yy * yy);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l;
    locs.resize(n);

    for (auto& loc : locs) cin >> loc.x >> loc.y;
    sort(locs.begin(), locs.end());

    vector<pii> up, down;

    for (auto& loc : locs) {
        while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], loc) >= 0)
            up.pop_back();
        up.push_back(loc);
        while (down.size() >= 2 && ccw(down[down.size() - 2], down[down.size() - 1], loc) <= 0)
            down.pop_back();
        down.push_back(loc);
    }
    up.insert(up.end(), down.rbegin() + 1, down.rend() - 1);

    double temp = 0;
    for (int i = 0; i < up.size(); ++i)
        temp += dist(up[i], up[(i + 1) % up.size()]);

    temp += 3.14159 * 2 * l;
    int ret = (int)temp;
    cout << (ret + (temp - ret >= 0.5 ? 1 : 0));
}