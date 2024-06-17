#include <iostream>

using namespace std;

const int _max = 2000000;
int n, k;
int tree[4 * _max];

void update(int node, int s, int e, int num) {
    if (s == e) {
        if(s == num) ++tree[node];
        return;
    }
    if (num < s || num > e) return;
    int mid = (s + e) >> 1;
    update(node * 2, s, mid, num);
    update(node * 2 + 1, mid + 1, e, num);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int search(int node, int s, int e, int x) {
    if (s == e) {
        --tree[node];
        return s;
    }
    int mid = (s + e) >> 1;
    int ret;
    if (tree[node * 2] >= x) {
        ret = search(node * 2, s, mid, x);
    }
    else {
        ret = search(node * 2 + 1, mid + 1, e, x - tree[node * 2]);
    }

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int t, x;
    while (n--) {
        cin >> t >> x;
        if (t == 1)  update(1, 1, _max, x);
        else cout << search(1, 1, _max, x) << "\n";
    }
}