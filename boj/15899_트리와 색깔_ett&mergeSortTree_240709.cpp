#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int _MAX = 200001, MOD = 1e9 + 7;

int n, m, c;

struct FT{
    int f, t;
}fts[_MAX];
int color[_MAX];
vector<int> con[_MAX];

vector<int> tree[_MAX * 4];
void insert(int node, int l, int r, int idx, int val) {
    if (l > idx || r < idx) return;
    tree[node].push_back(val);
    if (l == r) return;
    int mid = (l + r) >> 1;
    insert(node * 2, l, mid, idx, val);
    insert(node * 2 + 1, mid+1, r, idx, val);
}

int order = 1;
bool visit[_MAX];
void makeFT(int node) {
    visit[node] = true;
    fts[node].f = order;
    for (int& next : con[node]) {
        if (visit[next]) continue;
        makeFT(next);
    }
    insert(1, 1, n, order, color[node]);
    fts[node].t = order++;
}

int getLowEqualCnt(int node, int val) {
    auto& Node = tree[node];
    return upper_bound(Node.begin(), Node.end(), val) - Node.begin();
}

int query(int node, int l, int r, int s, int e, int val) {
    if (r < s || l > e) return 0;
    if (s <= l && r <= e) return getLowEqualCnt(node, val);
    int mid = (l + r) >> 1;
    return query(node * 2, l, mid, s, e, val) + query(node * 2+1, mid+1, r, s, e, val);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) cin >> color[i];
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        con[a].push_back(b);
        con[b].push_back(a);
    }
    makeFT(1);
    for (int i = 1; i < n * 4; ++i) sort(tree[i].begin(), tree[i].end());
    
    int V, C, ret = 0;
    while (m--) {
        cin >> V >> C;
        ret = (ret + query(1, 1, n, fts[V].f, fts[V].t, C)) % MOD;
    }
    cout << ret;
}
