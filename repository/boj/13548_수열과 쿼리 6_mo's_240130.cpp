#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m;
int arr[100000];

struct Query {
    int l, r, idx;
}queries[100000];

int cnt[100001];
int minusCntCnt[100001];
int cntCnt[100001];

int ret = 0;
int answer[100001];
void add(int num) {
    --cntCnt[cnt[num]];
    ret = max(ret, ++cnt[num]);
    ++cntCnt[cnt[num]];
}

void pop(int num) {
    --cntCnt[cnt[num]];
    if (cnt[num] == ret && !cntCnt[cnt[num]]) ret--;
    cntCnt[--cnt[num]]++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        Query& q = queries[i];
        cin >> q.l >> q.r;
        --q.l; --q.r; q.idx = i;
    }

    int batch = sqrt(n);
    sort(queries, queries + m, [&](Query& q1, Query& q2) {
        int b1 = q1.l / batch, b2 = q2.l / batch;
        return b1 < b2 || (b1 == b2 && q1.r < q2.r);
    });

    auto [l, r, tIdx] = queries[0];
    for (int i = l; i <= r; ++i) add(arr[i]);
    answer[tIdx] = ret;

    for (int i = 1; i < m; ++i) {
        auto& [tl, tr, idx] = queries[i];

        while (l < tl) pop(arr[l++]);
        while (l > tl) add(arr[--l]);
        while (r < tr) add(arr[++r]);
        while (r > tr) pop(arr[r--]);
        
        answer[idx] = ret;
    }

    for (int i = 0; i < m; ++i) cout << answer[i] << "\n";
}