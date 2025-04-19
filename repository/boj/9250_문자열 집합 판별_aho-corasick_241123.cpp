#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, q;

class AhoCorasick {
private:
    class Node {
    public:
        Node* children[26];
        Node* fail = nullptr;
        bool output = false;
    };
    Node* root = new Node();
public:
    void insert(const string& pattern) {
        Node* temp = root;
        for (char c : pattern) {
            auto& child = temp->children[c - 'a'];
            if (!child) child = new Node();
            temp = child;
        }
        temp->output = true;
    }
    void buildFail() {
        queue<Node*> q;
        root->fail = root;

        for (int i = 0; i < 26; ++i) {
            Node* child = root->children[i];
            if (child) {
                child->fail = root;
                q.push(child);
            }
        }

        while (q.size()) {
            Node* cur = q.front(); q.pop();

            for (int i = 0; i < 26; ++i) {
                Node* child = cur->children[i];
                if (!child) continue;

                Node* fail = cur->fail;
                while (fail != root && fail->children[i] == nullptr) {
                    fail = fail->fail;
                }
                if (fail->children[i]) {
                    child->fail = fail->children[i];
                }
                else child->fail = root;

                if (child->fail->output) child->output = true;
                q.push(child);
            }
        }
    }
    bool search(const string& pattern) {
        Node* temp = root;
        for (char c : pattern) {
            int idx = c - 'a';
            while (temp != root && temp->children[idx] == nullptr) {
                temp = temp->fail;
            }
            if (temp->children[idx]) {
                temp = temp->children[idx];
            }
            if (temp->output) return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    AhoCorasick ac;
    string pattern;
    while (n--) {
        cin >> pattern;
        ac.insert(pattern);
    }
    ac.buildFail();

    cin >> q;
    while (q--) {
        cin >> pattern;
        cout << (ac.search(pattern) ? "YES" : "NO") << "\n";
    }
}