#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

using ll = long long;

struct Cnt{
    int start = 0, end = 0;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int _min = 2e9;
        map<int, Cnt> cnt;

        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s;
            ++cnt[s].start;
            _min = min(_min, s);
        }

        for (int i = 0; i < n; ++i) {
            int e;
            cin >> e;
            ++cnt[e].end;
        }

        int negativeCnt = 0, buy = n;
        ll ret = 1LL * _min * n;
        for (auto& [price, cnt] : cnt) {
            if (cnt.start > 0) {
                if (negativeCnt <= k) {
                    ret = max(ret, 1LL * price * buy);
                }
                negativeCnt += cnt.start;
            }
            if (cnt.end > 0) {
                if (negativeCnt <= k) {
                    ret = max(ret, 1LL * price * buy);
                }
                negativeCnt -= cnt.end;
                buy -= cnt.end;
            }
        }

        cout << ret << "\n";
    }
}