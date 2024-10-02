#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

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

bool isMatch[100000][500];
void kmp(const string& l, const string& s, int wordIdx) {
    int n = l.size(), m = s.size();

    vector<int> pi = failureFunction(s);
    for (int i = 0, length = 0; i < n; ++i) {
        while (length > 0 && l[i] != s[length]) {
            length = pi[length - 1];
        }
        if (l[i] == s[length]) {
            ++length;
            if (length == m) {
                isMatch[i - m + 1][wordIdx] = true;
                length = pi[length - 1];
            }
        }
    }
}

int dp[100000];
int solve(int idx, const string& l, const vector<string>& words) {
    if (idx == l.size()) return 0;
    int& ret = dp[idx];
    if (ret != -1) return ret;

    ret = solve(idx + 1, l, words);
    for (int i = 0; i < N; ++i) {
        if (isMatch[idx][i]) {
            int length = words[i].size();
            ret = max(ret, length + solve(idx + length, l, words));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string L;
    cin >> L>>N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
        kmp(L, words[i], i);
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, L, words);
}