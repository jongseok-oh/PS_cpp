#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class AhoCorasick {
    struct Node {
        int child[26];
        int fail = -1;
        int lentgh = 0;
    };
    int root;
    vector<Node> trie;
    int getNode() {
        trie.push_back(Node());
        return trie.size() - 1;
    }
public:
    AhoCorasick() {
        root = getNode();
    }
    void insert(string& s) {
        int cur = root;
        for (char c : s) {
            if (!trie[cur].child[c - 'a']) {
                trie[cur].child[c - 'a'] = getNode();
            }
            cur = trie[cur].child[c - 'a'];
        }
        trie[cur].lentgh = s.size();
    }
    void build() {
        queue<int> q;

        trie[root].fail = root;
        for (int i = 0; i < 26; ++i) {
            int child = trie[root].child[i];
            if (child) {
                trie[child].fail = root;
                q.push(child);
            }
        }

        while (q.size()) {
            int parent = q.front(); q.pop();

            for (int i = 0; i < 26; ++i) {
                int cur = trie[parent].child[i];
                if (!cur) continue;

                int fail = trie[parent].fail;
                while (fail != root && !trie[fail].child[i]) {
                    fail = trie[fail].fail;
                }
                if (trie[fail].child[i]) fail = trie[fail].child[i];

                trie[cur].fail = fail;
                q.push(cur);
            }
        }
    }

    string solve(string& s) {
        int n = s.size();
        vector<int> stack(1, root);
        string ret;
        unordered_map<int, int> dp[26];
        for (int i = 0; i < n; ++i) {
            ret.push_back(s[i]);

            int c = s[i] - 'a';
            int cur = stack.back();

            if (dp[c].count(cur)) {
                cur = dp[c][cur];
            }
            else {
                int prev = cur;
                while (cur != root && !trie[cur].child[c]) {
                    cur = trie[cur].fail;
                }
                if (trie[cur].child[c]) cur = trie[cur].child[c];
                dp[c][prev] = cur;
            }

            stack.push_back(cur);
            
            int matchLen = trie[cur].lentgh;
            if (matchLen > 0) {
                ret.resize(ret.size() - matchLen);
                stack.resize(ret.size() + 1);
            }
        }

        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;

    int n; cin >> n;
    AhoCorasick ac;
    string pattern;
    while (n--) {
        cin >> pattern;
        ac.insert(pattern);
    }
    ac.build();
    cout << ac.solve(s);
}