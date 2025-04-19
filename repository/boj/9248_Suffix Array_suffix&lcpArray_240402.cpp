#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int _max = 500001;
int n, t = 1;
string s;

int sa[_max], group[_max], nGroup[_max-1];

bool cmp(int a, int b) {
    // group[a] == group[b]라는건
    // 부분문자열의 길이가 t 이상이라는 뜻 (n까지 도착하는데 t이상)
    // 따라서 a + t와 b + t는 모두 n 이하
    if (group[a] == group[b])
        return group[a + t] < group[b + t];
    return group[a] < group[b];
}

// O(nlogn^2)
void sortSuffixArray() {
    for (int i = 0; i < n; ++i) {
        group[i] = s[i];
        sa[i] = i;
    }
    group[n] = -1;
    while (true) {
        sort(sa, sa + n, cmp); // 이걸 radix sort로 바꿀 수 있다함 ㄱ-
        
        if (t * 2 >= n) break; // short cut

        nGroup[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (cmp(sa[i - 1], sa[i]))
                nGroup[sa[i]] = nGroup[sa[i - 1]] + 1;
            else nGroup[sa[i]] = nGroup[sa[i - 1]];
        }
        
        for (int i = 0; i < n; ++i)
            group[i] = nGroup[i];

        t <<= 1;
    }
}

int isa[_max], lcp[_max];
void makeLcp() {
    for (int i = 0; i < n; ++i) isa[sa[i]] = i;
    
    for (int i = 0, k = 0; i < n; ++i, k = max(k-1, 0)){
        if (isa[i] == 0) continue;

        int j = sa[isa[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
        lcp[isa[i]] = k;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    sortSuffixArray();
    
    for (int i = 0; i < n; ++i) cout << sa[i] + 1 << " ";
    cout << "\n";

    makeLcp();
    cout << "x ";
    
    for (int i = 1; i < n; ++i) cout << lcp[i] << " ";
}