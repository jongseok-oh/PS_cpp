#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, m;

class AhoCorasick {
    struct Node {
        map<char, int> child;
        int fail = -1;
        int size;
    };
    vector<Node> Trie;

    int makeNode() {
        Trie.emplace_back(Node());
        return Trie.size() - 1;
    }
public:
    AhoCorasick() {
        makeNode();
    }
    void insert(string& str) {
        int temp = 0;
        for (char c : str) {
            if (!Trie[temp].child.count(c)) {
                Trie[temp].child[c] = makeNode();
            }
            temp = Trie[temp].child[c];
        }
        Trie[temp].size = str.size();
    }
    void buldFail() {
        queue<int> q;
        Trie[0].fail = 0;

        for (auto& [c, next] : Trie[0].child) {
            Trie[next].fail = 0;
            q.push(next);
        }

        while (q.size()) {
            int parent = q.front(); q.pop();

            for (auto& [c, next] : Trie[parent].child) {
                int fail = Trie[parent].fail;
                while (fail && !Trie[fail].child.count(c)) {
                    fail = Trie[fail].fail;
                }

                if (Trie[fail].child.count(c)) {
                    Trie[next].fail = Trie[fail].child[c];
                }
                else Trie[next].fail = 0;

                Trie[next].size = max(Trie[next].size, Trie[Trie[next].fail].size);
                q.push(next);
            }
        }
    }
    int search(string& str) {
        int temp = 0, n = str.size();
        vector<bool> visit(n);
        for (int i = 0; i < n; ++i) {
            char c = str[i];
            while (temp && !Trie[temp].child.count(c)) {
                temp = Trie[temp].fail;
            }
            if (Trie[temp].child.count(c)) {
                temp = Trie[temp].child[c];
            }
            int matchSize = Trie[temp].size;
            if (matchSize) {
                for (int j = i - matchSize + 1; j <= i; ++j) {
                    visit[j] = true;
                }
            }
        }
        int totMatch = 0;
        for (bool v : visit) totMatch += v;

        return n - totMatch;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string street;
    cin >> n >> street >> m;

    string tile;
    AhoCorasick ac;
    while (m--) {
        cin >> tile;
        ac.insert(tile);
    }
    ac.buldFail();
    cout << ac.search(street);
}