#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

struct Rank {
    int f, s, t;
}ranks[500001];

int tree[2000010];

int query(int node, int l, int r, int s, int e) {
    if (l > e || r < s) return 0x7fffffff;
    if (l <= s && r >= e) return tree[node];
    int mid = (s + e) >> 1;
    return min(query(node * 2, l, r, s, mid), query(node * 2 + 1, l, r, mid + 1, e));
}

void update(int node, int idx, int s, int e, int val) {
    if (s > idx || e < idx) return;
    if (s == e) { tree[node] = val; return; }
    int mid = (s + e) >> 1;
    update(node * 2, idx, s, mid, val);
    update(node * 2 + 1, idx, mid+1, e, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int num;
    for (int i = 1; i <= n; ++i) cin >> num, ranks[num].f = i;
    for (int i = 1; i <= n; ++i) cin >> num, ranks[num].s = i;
    for (int i = 1; i <= n; ++i) cin >> num, ranks[num].t = i;

    sort(ranks + 1, ranks + n + 1, [&](Rank& a, Rank& b) {return a.f < b.f; });

    memset(tree, 0x7f, n * 16);

    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (query(1, 1, ranks[i].s, 1, n) > ranks[i].t) ret++;
        update(1, ranks[i].s, 1, n, ranks[i].t);
    }
    cout << ret;
}