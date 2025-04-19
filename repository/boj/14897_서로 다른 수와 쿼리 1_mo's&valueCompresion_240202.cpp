#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

int n, q;
int arr[1000001];
int temp[1000001];
unordered_map<int, int> mapper;

struct Q{
    int l,r,idx;
}qs[1000000];

int cnt[1000001];

int ret = 0;
int answer[1000000];

void add(int num) {
    if (cnt[num]++ == 0) ret++;
}

void pop(int num) {
    if (--cnt[num] == 0) ret--;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    sort(temp + 1, temp + n + 1);
    int idx = 1;
    mapper[temp[1]] = idx;
    for (int i = 2; i <= n; ++i)
        if (temp[i] != temp[i - 1])
            mapper[temp[i]] = ++idx;

    for (int i = 1; i <= n; ++i) arr[i] = mapper[arr[i]];

    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].idx = i;
    }

    int batch = sqrt(n);
    sort(qs, qs + q, [&](Q& q1, Q& q2) {
        int b1 = q1.l / batch, b2 = q2.l / batch;
        return b1 < b2 || (b1 == b2 && q1.r < q2.r);
    });

    int l = 0, r = 0;
    for (int i = 0; i < q; ++i) {
        auto& [tl, tr, idx] = qs[i];
        
        while (l < tl) pop(arr[l++]);
        while (l > tl) add(arr[--l]);
        while (r < tr) add(arr[++r]);
        while (r > tr) pop(arr[r--]);

        answer[idx] = ret;
    }

    for (int i = 0; i < q; ++i) cout << answer[i] << "\n";
}