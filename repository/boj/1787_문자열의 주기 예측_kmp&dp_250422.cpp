#include <iostream>
#include <vector>

using ll = long long;

using namespace std;

vector<int> failureFunction(string& s) {
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1, length = 0; i < n; ++i) {
        while (length && s[length] != s[i]) {
            length = pi[length - 1];
        }
        if (s[length] == s[i]) pi[i] = ++length;
    }

    return pi;
}

int getP(int idx, vector<int>& pi, vector<int>& dp) {
    int& ret = dp[idx];
    if (ret != -1) return ret;
    if (pi[idx] == 0) return ret = 0;

    int child = getP(pi[idx]-1, pi, dp);
    return ret = child ? child : pi[idx];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s;
    cin >>n>> s;
    vector<int> pi = failureFunction(s), dp(n, -1);
    
    ll ret = 0;
    for (int i = n-1; i > 0; --i) {
        int t = getP(i, pi, dp);
        ret += t?i + 1 - t:0;
    }
    cout << ret;
}