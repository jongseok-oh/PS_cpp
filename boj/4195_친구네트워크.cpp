#include <iostream>
#include <unordered_map>

using namespace std;

struct info {
    string parent;
    int cnt = -1;
};

unordered_map<string, info> m;

string getP(string t) {
    if (m[t].cnt < 0) return t;
    return m[t].parent = getP(m[t].parent);
}

void Union(string f1, string f2) {
    string p1 = getP(f1);
    string p2 = getP(f2);

    if (p1 == p2) {
        cout << -m[p1].cnt << "\n";
        return;
    }

    m[p2].parent = p1;
    m[p1].cnt += m[p2].cnt;
    m[p2].cnt = 30;

    cout << -m[p1].cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int t; cin >> t;

    while (t--) {
        int f; cin >> f;
        m.clear();
        while (f--) {
            string f1, f2;
            cin >> f1 >> f2;
            Union(f1, f2);
        }
    }
}