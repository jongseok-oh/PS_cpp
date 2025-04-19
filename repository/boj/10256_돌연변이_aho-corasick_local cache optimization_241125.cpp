#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int getIdx(char c) {
    switch (c)
    {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    }
    return -1;
}

class AhoCorasick {
private:
    struct Node{
        int child[4];
        int fail;
        bool output;
        Node() {
            memset(child, -1, sizeof child);
            fail = -1;
            output = false;
        }
    };
    vector<Node> trie;
    int newNode() {
        trie.emplace_back(Node());
        return trie.size() - 1;
    }
public:
    AhoCorasick() {
        newNode();
    }
    void insert(const string& str) {
        int temp = 0;
        for (char c : str) {
            int child = trie[temp].child[getIdx(c)];
            if (child == -1) {
                child = trie[temp].child[getIdx(c)] = newNode();
            }
            temp = child;
        }
        trie[temp].output = true;
    }
    void buldFail() {
        queue<int> q;
        trie[0].fail = 0;

        for (int i = 0; i < 4; ++i) {
            int next = trie[0].child[i];
            if (next != -1) {
                trie[next].fail = 0;
                q.push(next);
            }
        }

        while (q.size()) {
            int parent = q.front(); q.pop();

            for (int i = 0; i < 4; ++i) {
                int next = trie[parent].child[i];
                if (next == -1) continue;;

                int fail = trie[parent].fail;
                while (fail && trie[fail].child[i] == -1) {
                    fail = trie[fail].fail;
                }

                if (trie[fail].child[i] != -1) {
                    trie[next].fail = trie[fail].child[i];
                }
                else trie[next].fail = 0;

                trie[next].output |= trie[trie[next].fail].output;
                q.push(next);
            }
        }
    }
    int search(const string& str) {
        int cnt = 0;
        int temp = 0;
        for (char c : str) {
            int cIdx = getIdx(c);
            while (temp && trie[temp].child[cIdx] == -1) {
                temp = trie[temp].fail;
            }
            if (trie[temp].child[cIdx] != -1) temp = trie[temp].child[cIdx];
            if (trie[temp].output) ++cnt;
        }
        return cnt;
    }

    void clear() {
        trie.clear();
        newNode();
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;

    int n, m;
    string dna, marker;
    AhoCorasick ac;
    while (T--) {
        cin >> n>> m >> dna >> marker;
        
        for (int left = 0; left < m; ++left) {
            for (int mid = 1; mid <= m - left; ++mid) {
                string mutation = marker;
                reverse(mutation.begin() + left, mutation.begin() + (left + mid));
                ac.insert(mutation);
            }
        }

        ac.buldFail();
        cout << ac.search(dna) << "\n";
        ac.clear();
    }
}