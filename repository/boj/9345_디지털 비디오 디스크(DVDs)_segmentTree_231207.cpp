#include <iostream>

#define _MAX 100000

using namespace std;

int n, k;

int minTree[_MAX * 4];
int maxTree[_MAX * 4];

void initMinTree(int node, int l, int r) {
    if (l == r) {
        minTree[node] = l; return;
    }

    int mid = (l + r) >> 1;
    initMinTree(node * 2, l, mid);
    initMinTree(node * 2 + 1, mid + 1, r);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
}

void initMaxTree(int node, int l, int r) {
    if (l == r) {
        maxTree[node] = l; return;
    }

    int mid = (l + r) >> 1;
    initMaxTree(node * 2, l, mid);
    initMaxTree(node * 2 + 1, mid + 1, r);
    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

void init() {
    initMinTree(1, 0, n - 1);
    initMaxTree(1, 0, n - 1);
}

int getMin(int node, int l, int r, int s, int e) {
    if (r < s || e < l) return 1e9;
    if (l <= s && r >= e) return minTree[node];
    int mid = (s + e) >> 1;
    return min(getMin(node * 2, l, r, s, mid), getMin(node * 2 + 1, l, r, mid + 1, e));
}

int getMax(int node, int l, int r, int s, int e) {
    if (r < s || e < l) return -1;
    if (l <= s && r >= e) return maxTree[node];
    int mid = (s + e) >> 1;
    return max(getMax(node * 2, l, r, s, mid), getMax(node * 2 + 1, l, r, mid + 1, e));
}

void _update(int node, int idx, int val, int s, int e) {
    if (idx < s || e < idx) return;
    if (s == e) {
        maxTree[node] = val;
        minTree[node] = val;
        return;
    }
    int mid = (s + e) >> 1;
    _update(node * 2, idx, val, s, mid);
    _update(node * 2 + 1, idx, val, mid + 1, e);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

void _swap(int a, int b) {
    // a, b 선반에 있는 dvd
    int aNum = getMin(1, a, a, 0, n - 1);
    int bNum = getMin(1, b, b, 0, n - 1);
    _update(1, a, bNum, 0, n - 1);
    _update(1, b, aNum, 0, n - 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> k;
        init();

        int q, a, b;
        while (k--) {
            cin >> q >> a >> b;

            if (q) {
                int _min = getMin(1, a, b, 0, n - 1);
                int _max = getMax(1, a, b, 0, n - 1);

                cout << (_min == a && _max == b ? "YES\n" : "NO\n");
            }
            else _swap(a, b);
        }
    }
}