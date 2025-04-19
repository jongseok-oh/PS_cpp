#include <iostream>
#include <vector>

using namespace std;

vector<int> failureFunction(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int length = pi[i - 1];
        while (length > 0 && s[i] != s[length]) {
            length = pi[length - 1];
        }
        if (s[i] == s[length]) ++length;
        pi[i] = length;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l; string s;
    cin >> l >> s;
    vector<int> pi = failureFunction(s);
    cout << l - pi.back();
}