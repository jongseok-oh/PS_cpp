#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class AhoCorasick {
    struct Node {
        int child[3];
        int fail;
        int cnt;
        Node() {
            memset(child, -1, 4 * 3);
            fail = -1;
            cnt = 0;
        }
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
    void insert(string& str) {
        int cur = root;
        for (char c : str) {
            if (trie[cur].child[c - 'A'] == -1) {
                trie[cur].child[c - 'A'] = getNode();
            }
            cur = trie[cur].child[c - 'A'];
        }
        trie[cur].cnt++;
    }

    void buildFail() {
        trie[root].fail = root;

        queue<int> q;
        for (int i = 0; i < 3; ++i) {
            int child = trie[root].child[i];
            if (child != -1) {
                trie[child].fail = root;
                q.push(child);
            }
        }

        while (q.size()) {
            int parent = q.front(); q.pop();

            for (int i = 0; i < 3; ++i) {
                int cur = trie[parent].child[i];
                if (cur == -1) continue;

                int fail = trie[parent].fail;
                while(fail != root && trie[fail].child[i] == -1) {
                    fail = trie[fail].fail;
                }

                if (trie[fail].child[i] != -1) {
                    trie[cur].fail = trie[fail].child[i];
                }
                else trie[cur].fail = root;

                trie[cur].cnt += trie[trie[cur].fail].cnt;
                q.push(cur);
            }
        }
    }

    int solve(int len) {
        int m = trie.size();
        vector<int> dp(m, -1);
        dp[root] = 0;
        while (len--) {
            vector<int> nDp(m, -1);
            for (int node = 0; node < m; ++node) {
                if (dp[node] == -1) continue;
                
                for (int c = 0; c < 3; ++c) {
                    int cur = node;
                    while (cur != root && trie[cur].child[c] == -1) {
                        cur = trie[cur].fail;
                    }
                    if (trie[cur].child[c] != -1) {
                        cur = trie[cur].child[c];
                    }

                    nDp[cur] = max(nDp[cur], dp[node] + trie[cur].cnt);
                }
            }
            swap(dp, nDp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;

    AhoCorasick ac;
    string pattern;
    for (int i = 0; i < n; ++i) {
        cin >> pattern;
        ac.insert(pattern);
    }
    ac.buildFail();
    cout << ac.solve(k);
}