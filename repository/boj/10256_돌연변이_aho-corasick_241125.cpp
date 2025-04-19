#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int mapper[26];
int getIdx(char c) {
    return mapper[c - 'A'];
}

class AhoCorasick {
private:
    class Node{
    public:
        Node* child[4];
        Node* fail;
        bool output;
    };
    Node* root = new Node();
public:
    ~AhoCorasick() {
        queue<Node*> q;
        q.push(root);

        while (q.size()) {
            Node* temp = q.front(); q.pop();

            for (int i = 0; i < 4; ++i) {
                if (temp->child[i]) {
                    q.push(temp->child[i]);
                }
            }

            delete temp;
        }
    }
    void insert(const string& str) {
        Node* temp = root;
        for (char c : str) {
            auto& child = temp->child[getIdx(c)];
            if (!child) child = new Node();
            temp = child;
        }
        temp->output = true;
    }
    void buldFail() {
        queue<Node*> q;
        root->fail = root;

        for (int i = 0; i < 4; ++i) {
            Node* next = root->child[i];
            if (next) {
                next->fail = root;
                q.push(next);
            }
        }

        while (q.size()) {
            Node* parent = q.front(); q.pop();

            for (int i = 0; i < 4; ++i) {
                Node* next = parent->child[i];
                if (!next) continue;

                Node* fail = parent->fail;
                while (fail != root && fail->child[i] == nullptr) {
                    fail = fail->fail;
                }

                if (fail->child[i]) {
                    next->fail = fail->child[i];
                }
                else next->fail = root;

                if (next->fail->output) next->output = true;

                q.push(next);
            }
        }
    }
    int search(const string& str) {
        int cnt = 0;
        Node* temp = root;
        for (char c : str) {
            int cIdx = getIdx(c);
            while (temp != root && temp->child[cIdx] == nullptr) {
                temp = temp->fail;
            }
            if (temp->child[cIdx]) temp = temp->child[cIdx];
            if (temp->output) ++cnt;
        }
        return cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    
    mapper['A' - 'A'] = 0;
    mapper['C' - 'A'] = 1;
    mapper['G' - 'A'] = 2;
    mapper['T' - 'A'] = 3;

    int n, m;
    string dna, marker;
    while (T--) {
        cin >> n>> m >> dna >> marker;
        AhoCorasick ac;

        for (int left = 0; left < m; ++left) {
            for (int mid = 1; mid <= m - left; ++mid) {
                int right = m - (left + mid);
                string first = marker.substr(0, left);
                string second = marker.substr(left, mid);
                reverse(second.begin(), second.end());
                string third = marker.substr(left + mid, right);
                
                string mutation = first + second + third;
                
                ac.insert(mutation);
            }
        }

        ac.buldFail();
        cout << ac.search(dna) << "\n";
    }
}