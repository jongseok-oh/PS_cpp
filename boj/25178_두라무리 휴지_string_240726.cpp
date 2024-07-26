#include <iostream>
#include <string>

using namespace std;

char vowel[] = { 'a','e','i','o','u' };
bool isVowel(char c) {
    for (int i = 0; i < 5; ++i) {
        if (vowel[i] == c) return true;
    }
    return false;
}

int cnt1[26], cnt2[26];
string noVowel(string& s, int * cnt) {
    string t;
    for (char c : s) {
        if (!isVowel(c)) t += c;
        else cnt[c - 'a']++;
    }
    return t;
}

string solve(string& a, string& b, int n) {
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        return "NO";
    }
    string t1 = noVowel(a, cnt1), t2 = noVowel(b, cnt2);
    if (t1 != t2) return "NO";

    for (int i = 0; i < 5; ++i) {
        int idx = vowel[i] - 'a';
        if (cnt1[idx] != cnt2[idx]) return "NO";
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string a, b;
    cin >> n>>a>>b;
    cout << solve(a, b, n);
}