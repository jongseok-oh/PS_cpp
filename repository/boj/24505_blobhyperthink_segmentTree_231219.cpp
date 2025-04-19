#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int n;
int tree[12][400000];

void update(int node, int idx, int val, int s, int e, int len) {
    if (idx <s || idx > e) return;
    if (s == e) {
        tree[len][node] = (tree[len][node] + val)%MOD;
        return;
    }
    int mid = (s + e) >> 1;
    update(node * 2, idx, val, s, mid, len);
    update(node * 2 +1, idx, val, mid+1, e, len);
    tree[len][node] = (tree[len][node * 2] + tree[len][node * 2 + 1]) % MOD;
}

int query(int node, int idx, int s, int e, int len) {
    if (s > idx) return 0;
    if (e <= idx) return tree[len][node];
    int mid = (s + e) >> 1;
    return (
        query(node * 2, idx, s, mid, len) + query(node * 2 + 1, idx, mid + 1, e, len)
        ) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        update(1, a, 1, 1, n, 1);
        for (int j = 2; j < 12; ++j) 
            update(1, a, query(1, a - 1, 1, n, j - 1), 1, n, j);
    }
    cout << tree[11][1];
}