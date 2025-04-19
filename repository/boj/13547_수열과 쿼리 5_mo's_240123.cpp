#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n,m;
int arr[100001];

struct Query { int idx, l, r; };
Query queries[100000];

int cnts[1000001];
int answers[100000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        queries[i] = { i,l,r };
    }

    int batch = sqrt(n);
    sort(queries, queries + m, [&](Query& q1, Query& q2) {
        return q1.l / batch < q2.l / batch || (q1.l / batch == q2.l / batch && q1.r < q2.r);
    });

    int ret = 0;
    auto& [tempIdx, l, r] = queries[0];
    for (int i = l; i <= r; ++i)
        if (!cnts[arr[i]]++) ++ret;
    answers[tempIdx] = ret;

    for (int i = 1; i < m; ++i) {
        auto& [idx, tL, tR] = queries[i];
        while (l < tL) if(--cnts[arr[l++]] == 0) ret--;
        while (l > tL) if(cnts[arr[--l]]++ == 0) ret++;
        while (r < tR) if (cnts[arr[++r]]++ == 0) ret++;
        while (r > tR) if (--cnts[arr[r--]] == 0) ret--;
        answers[idx] = ret;
    }

    for (int i = 0; i < m; ++i) cout << answers[i] << "\n";
}