#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
int hashing(int h, char c,int prime) {
    return (1LL * h * prime + c - 'a' + 1) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;

    int n; cin >> n;
    string pattern;

    const int prime = 31;
    unordered_map<int, unordered_set<int>> t;
    while (n--) {
        cin >> pattern;
        int h = 0;
        for (char c : pattern) {
            h = hashing(h, c, prime);
        }
        t[pattern.size()].insert(h);
    }
    
    vector<int> prevHash(1, 0), prevPow(1, 1);
    string ret;
    for (char c : s) {
        ret.push_back(c);

        int nHash = hashing(prevHash.back(), c, prime);
        prevHash.push_back(nHash);
        prevPow.push_back(1LL * prevPow.back() * prime % MOD);
        
        for (const auto& [len, hashes] : t) {
            if (len > ret.size()) continue;
            
            int prefixHash = 1LL * prevHash[ret.size() - len] * prevPow[len] % MOD;
            int lenHash = (prevHash.back() - prefixHash + MOD) % MOD;

            if (hashes.count(lenHash)) {
                ret.resize(ret.size() - len);
                prevHash.resize(prevHash.size() - len);
                prevPow.resize(prevPow.size() - len);
                break;
            }
        }
    }

    for (char c : ret) cout << c;
}