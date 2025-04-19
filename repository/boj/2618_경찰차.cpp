#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, w;

struct loc {int y, x;};

loc problems[1002];

int dp[1002][1002];

int getDist(loc loc1, loc loc2) {
    return abs(loc1.y - loc2.y) + abs(loc1.x - loc2.x);
}

int solve(int car1, int car2) {
    int tp = max(car1, car2) + 1;
    int& ret = dp[car1][car2];
    if (tp >= w + 2) return ret = 0;

    if (ret != -1) return ret;

    ret = solve(tp, car2) + getDist(problems[tp], problems[car1]);

    return ret = min(ret, solve(car1, tp) + getDist(problems[tp], problems[car2]));
}

void trace(int car1, int car2) {
    int tp = max(car1, car2) + 1;
    if (tp >= w + 2) return;

    int dist1 = solve(tp, car2) + getDist(problems[tp], problems[car1]);
    int dist2 = solve(car1, tp) + getDist(problems[tp], problems[car2]);

    if (dist1 > dist2) {
        cout << 2 << "\n";
        trace(car1, tp);
    }
    else {
        cout << 1 << "\n";
        trace(tp, car2);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0);
    
    cin >> n >> w;

    problems[0] = { 1,1 };
    problems[1] = { n, n};
    for (int i = 2; i <=w+1; i++) cin >> problems[i].y >> problems[i].x;
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 1) << "\n";
    trace(0, 1);
}