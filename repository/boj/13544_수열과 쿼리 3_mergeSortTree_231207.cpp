#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int arr[100001];
vector<int> msTree[400000];

void init(int node, int l, int r) {
    if (l == r) {
        msTree[node] = { arr[l] };
        return;
    }
    int mid = (l + r) >> 1;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    msTree[node].insert(msTree[node].end(), msTree[node * 2].begin(), msTree[node * 2].end());
    msTree[node].insert(msTree[node].end(), msTree[node * 2 + 1].begin(), msTree[node * 2 + 1].end());
}

int query(int node, int k, int l, int r, int s, int e) {
    if (r < s || l > e) return 0;
    if (l <= s && e <= r) {
        return msTree[node].end()
            - upper_bound(msTree[node].begin(), msTree[node].end(), k);
    }
    int mid = (s + e) >> 1;
    return query(node * 2, k, l, r, s, mid) + query(node * 2 + 1, k, l, r, mid + 1, e);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> arr[i];
    init(1, 1, n);
    for (int i = 1; i < n * 4; ++i)
        sort(msTree[i].begin(), msTree[i].end());

    int last_ans = 0, m;
    int a, b, c, i, j, k;
    cin >> m;
    while (m--) {
        cin >> a >> b >> c;
        i = a ^ last_ans;
        j = b ^ last_ans;
        k = c ^ last_ans;

        last_ans = query(1, k, i, j, 1, n);
        cout << last_ans << "\n";
    }
}