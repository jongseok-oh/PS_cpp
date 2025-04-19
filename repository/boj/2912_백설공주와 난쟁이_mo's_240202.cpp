#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, c, m;

int hats[300001];

struct Q {
    int a, b, idx;
}qs[10000];

int cnt[10001];
int answer[10000];

int chk(int k) {
    for (int i = 1; i <= c; ++i)
        if (cnt[i] > k) return i;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) cin >> hats[i];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> qs[i].a >> qs[i].b;
        qs[i].idx = i;
    }

    int batch = sqrt(n);
    sort(qs, qs + m, [&](Q& q1, Q& q2) {
        int b1 = q1.a / batch, b2 = q2.a / batch;
        return b1 < b2 || (b1 == b2 && q1.b < q2.b);
    });

    int a = 0, b = 0;
    for (int i = 0; i < m; ++i) {
        auto& [ta, tb, idx] = qs[i];

        while (a < ta) cnt[hats[a++]]--;
        while (a > ta) cnt[hats[--a]]++;
        while (b < tb) cnt[hats[++b]]++;
        while (b > tb) cnt[hats[b--]]--;

        answer[idx] = chk((b - a + 1) / 2);
    }

    for (int i = 0; i < m; ++i) {
        if (answer[i]) cout << "yes " << answer[i] << "\n";
        else cout << "no\n";
    }
}