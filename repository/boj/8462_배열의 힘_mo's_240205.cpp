#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, t;

int arr[100001];

struct Q {
    int l, r, idx;
}qs[100000];

long long ans[100000];

int cnt[1000001];
long long ret = 0;

void add(int num) {
    ret += (2LL * cnt[num]++ + 1) * num;
}

void pop(int num) {
    ret += (-2LL * cnt[num]-- + 1) * num;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n>>t;

    for (int i = 1; i <= n; ++i) cin >> arr[i];

    for (int i = 0; i < t; ++i) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].idx = i;
    }

    int srt = sqrt(n);
    sort(qs, qs + t, [&](Q& q1, Q& q2) {
        int b1 = q1.l / srt, b2 = q2.l / srt;
        return b1 < b2 || (b1 == b2 && q1.r < q2.r);
    });

    int l = 0, r = 0;
    
    for (int i = 0; i < t; ++i) {
        auto& [tl, tr, idx] = qs[i];

        while (l > tl) add(arr[--l]);
        while (l < tl) pop(arr[l++]);
        while (r > tr) pop(arr[r--]);
        while (r < tr) add(arr[++r]);

        ans[idx] = ret;
    }

    for (int i = 0; i < t; ++i) cout << ans[i] << "\n";
}