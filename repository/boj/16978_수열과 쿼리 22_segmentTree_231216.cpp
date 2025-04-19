#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n,m;
ll arr[100001];

struct q1 { ll i, v; };
struct q2 { ll k, i, j,idx; };
vector<q1> query1;
vector<q2> query2;

ll tree[400000];

void init(int node, int r, int l) {
    if (r == l) {
        tree[node] = arr[r]; return;
    }
    int mid = (r + l) >> 1;
    init(node * 2, r, mid);
    init(node * 2 + 1, mid + 1, l);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int i, int v, int r, int l) {
    if (r > i || l < i) return;
    if (r == l) {
        tree[node] = v; return;
    }
    int mid = (r + l) >> 1;
    update(node * 2, i, v, r, mid);
    update(node * 2 + 1, i, v, mid+1, l);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getSum(int node, int s, int e, int r, int l) {
    if (s > l || e < r) return 0;
    if (s <= r && e >= l) return tree[node];
    int mid = (r + l) >> 1;
    return getSum(node * 2, s, e, r, mid) + getSum(node * 2 + 1, s, e, mid + 1, l);
}

struct ans { ll ret, idx; };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    init(1, 1, n);

    int idx = 0;
    cin >> m;
    while (m--) {
        ll q, k, i, j;
        cin >> q;
        if(q == 1){
            cin >> i >> j;
            query1.push_back({ i,j });
        }
        else {
            cin >> k >> i >> j;
            query2.push_back({ k,i,j,idx++});
        }
    }
    sort(query2.begin(), query2.end(), [&](auto& a, auto& b) {
        return a.k < b.k;
        });

    vector<ans> ret(query2.size());

    int tk = 0;
    for (int i = 0; i < query2.size(); ++i) {
        auto& q = query2[i];
        while (q.k > tk) {
            update(1, query1[tk].i, query1[tk].v, 1, n);
            tk++;
        }
        ret[i].ret = getSum(1, q.i, q.j, 1, n);
        ret[i].idx = q.idx;
    }

    sort(ret.begin(), ret.end(), [&](auto& a, auto& b) {return a.idx < b.idx;});
    for (ans& r : ret) cout << r.ret << "\n";
}