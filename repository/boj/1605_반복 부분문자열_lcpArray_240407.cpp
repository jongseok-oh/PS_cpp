#include <iostream>
#include <string>
#include <algorithm>

const int _max = 200001;

using namespace std;

int n;
string str;

int t = 1;
int sa[_max], group[_max], tGroup[_max];
bool cmp(int a, int b) {
    if (group[a] == group[b])
        return group[a + t] < group[b + t];
    return group[a] < group[b];
}
void makeSuffixArray() {
    for (int i = 0; i < n; ++i) {
        group[i] = str[i];
        sa[i] = i;
    }

    group[n] = -1;
    while (true) {
        sort(sa, sa + n, cmp);
        if (t * 2 >= n) break;

        tGroup[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (cmp(sa[i - 1], sa[i])) {
                tGroup[sa[i]] = tGroup[sa[i - 1]] + 1;
            }
            else tGroup[sa[i]] = tGroup[sa[i - 1]];
        }

        for (int i = 0; i < n; ++i)
            group[i] = tGroup[i];
        t <<= 1;
    }
}

int isa[_max], lcp[_max];
void makeLcpArray() {
    makeSuffixArray();
    for (int i = 0; i < n; ++i) isa[sa[i]] = i;

    for (int i = 0, k = 0; i < n; k = max(k - 1, 0), ++i) {
        if (isa[i] == 0) continue;

        int j = sa[isa[i] - 1];

        while (i + k < n && j + k < n && str[i + k] == str[j + k]) ++k;
        lcp[i] = k;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> str;
    makeLcpArray();

    cout << *max_element(lcp, lcp + n);
}