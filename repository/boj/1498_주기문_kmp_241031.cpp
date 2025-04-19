#include <iostream>
#include <vector>

using namespace std;

string s;

vector<int> failureFunction(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1, length = 0; i < n; ++i) {
        while (length > 0 && s[length] != s[i]) {
            length = pi[length - 1];
        }
        if (s[length] == s[i]) ++length;
        pi[i] = length;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    int n = s.size();
    vector<int> pi = failureFunction(s);
    for (int i = 1; i < n; ++i) {
        int totLen = i + 1, len = pi[i];
        if (len >= i / 2 + 1 && totLen % (totLen - len) == 0) {
            cout << totLen << " " << totLen / (totLen - len) << "\n";
        }
    }
}