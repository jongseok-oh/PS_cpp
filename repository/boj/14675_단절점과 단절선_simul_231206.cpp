#include <iostream>

using namespace std;

int n,q;

struct Edge {int a, b;}edges[100000];

int conCnt[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    int a, b;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        edges[i].a = a; edges[i].b = b;
        ++conCnt[a]; ++conCnt[b];
    }

    cin >> q;
    int t, k;
    while (q--) {
        cin >> t >> k;

        if (t == 1)
            cout << (conCnt[k] >= 2 ? "yes\n" : "no\n");
        else cout << "yes\n";
    }
}