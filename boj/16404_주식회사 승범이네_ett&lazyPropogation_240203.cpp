#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> con[100001];

int order = 0;
int s[100001], e[100001];
void dfs(int t) {
    s[t] = ++order;
    for (int& next : con[t])
        dfs(next);
    e[t] = order;
}

int lazyTree[400000];

void updateLazy(int node, int l, int r) {
    if (lazyTree[node] && l != r) {
        lazyTree[node * 2] += lazyTree[node];
        lazyTree[node * 2 + 1] += lazyTree[node];
        lazyTree[node] = 0;
    }
}

void update(int node, int l, int r, int s, int e, int val) {
    if (s > r || e < l) return;
    updateLazy(node, l, r);
    if (l >= s && r <= e) {
        lazyTree[node] += val; return;
    }
    int mid = (l + r) >> 1;
    update(node * 2, l, mid, s, e, val);
    update(node * 2 + 1, mid +1, r, s, e, val);
}

int get(int node, int l, int r, int idx){
    if (idx > r || idx < l) return 0;
    if (l == r) return lazyTree[node];
    updateLazy(node, l, r);
    int mid = (l + r) >> 1;
    return get(node * 2, l, mid, idx) + get(node * 2 + 1, mid + 1, r, idx);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n>>m;
    int p;
    for (int i = 1; i <= n; ++i) {
        cin >> p;
        if (p != -1) con[p].push_back(i);
    }
    dfs(1);

    while (m--) {
        int mode; cin >> mode;
        if (mode == 1) {
            int i, w; cin >> i >> w;
            update(1, 1, n, s[i], e[i], w);
        }
        else {
            int i; cin >> i;
            cout << get(1, 1, n, s[i]) << "\n";
        }
    }
}