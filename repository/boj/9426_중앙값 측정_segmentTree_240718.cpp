#include <iostream>

using namespace std;

const int _MAX = 65535;

using ll = long long;

int n, k;
int arr[250000];
int tree[_MAX * 4];

void update(int node, int idx, int l, int r,int val) {
    if (r == l) {
        tree[node] += val;
        return;
    }
    int mid = (l + r) >> 1;
    if(idx <= mid) update(node * 2, idx, l, mid, val);
    else update(node * 2 + 1, idx, mid+1, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int getCnt(int node, int l, int r, int tar) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (tree[node * 2] >= tar) return getCnt(node * 2, l, mid, tar);
    return getCnt(node * 2 + 1, mid+1, r, tar - tree[node * 2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
        update(1, arr[i], 0, _MAX, 1);
    }

    ll ret = 0;
    int tar = (k + 1) / 2;
    ret += getCnt(1, 0, _MAX, tar);

    for (int i = k; i < n; ++i) {
        cin >> arr[i];
        update(1, arr[i-k], 0, _MAX, -1);
        update(1, arr[i], 0, _MAX, 1);
        ret += getCnt(1, 0, _MAX, tar);
    }

    cout << ret;
}