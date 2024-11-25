#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;

int hp, wp, hm, wm;

int getIdx(char c) {
    return c == 'o';
}

class AhoCorasick {
    struct Node{
        int child[2];
        int fail;
        int output;
        Node() {
            memset(child, -1, sizeof child);
            fail = -1;
            output = -1;
        }
    };
    vector<Node> Trie;

    int getNode() {
        Trie.emplace_back(Node());
        return Trie.size() - 1;
    }
public:
    AhoCorasick() {
        getNode();
    }

    void insert(string& row, int idx) {
        int temp = 0;
        for (char c : row) {
            int next = Trie[temp].child[getIdx(c)];
            if (next == -1) {
                next = Trie[temp].child[getIdx(c)] = getNode();
            }
            temp = next;
        }
        Trie[temp].output = idx;
    }

    void buildFail() {
        queue<int> q;
        Trie[0].fail = 0;
        
        for (int i = 0; i < 2; ++i) {
            int next = Trie[0].child[i];
            if (next != -1) {
                q.push(next);
                Trie[next].fail = 0;
            }
        }

        while (q.size()) {
            int cur = q.front(); q.pop();

            for (int i = 0; i < 2; ++i) {
                int next = Trie[cur].child[i];
                if (next == -1) continue;
                
                int fail = Trie[cur].fail;
                while (fail && Trie[fail].child[i] == -1) {
                    fail = Trie[fail].fail;
                }
                
                if (Trie[fail].child[i] != -1) {
                    Trie[next].fail = Trie[fail].child[i];
                }
                else Trie[next].fail = 0;
                // 패턴 길이가 같아서 output link 생성 생략

                q.push(next);
            }
        }
    }

    void search(string& row, vector<vector<int>>& patternBoard) {
        vector<int> mappedRow(wm, 37);
        int temp = 0;
        for (int i = 0; i < wm; ++i) {
            int cIdx = getIdx(row[i]);
            while (temp && Trie[temp].child[cIdx] == -1) {
                temp = Trie[temp].fail;
            }
            if (Trie[temp].child[cIdx] != -1) {
                temp = Trie[temp].child[cIdx];
            }
            int output = Trie[temp].output;
            if (output != -1) mappedRow[i] = output;
        }
        patternBoard.emplace_back(mappedRow);
    }
};

int rabinKarp(int rHash, vector<vector<int>>& patternBoard) {
    int pows = 1;
    for (int i = 0; i < hp-1; ++i) {
        pows *= 31;
    }
    int ret = 0;
    for (int j = wp - 1; j < wm; ++j) {
        int tHash = 0;
        for (int i = 0; i < hp-1; ++i) {
            tHash = tHash * 31 + patternBoard[i][j];
        }
        for (int i = hp - 1; i < hm; ++i) {
            tHash = tHash * 31 + patternBoard[i][j];
            if (tHash == rHash) ++ret;
            tHash -= pows * patternBoard[i-(hp-1)][j];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> hp >> wp >> hm >> wm;

    string pRow;
    AhoCorasick ac;
    unordered_map<string, int> pRowMap;

    int resultHash = 0, idx = 1;
    for (int i = 0; i < hp; ++i) {
        cin >> pRow;
        if (!pRowMap.count(pRow)) {
            pRowMap[pRow] = idx++;
            ac.insert(pRow, pRowMap[pRow]);
        }
        resultHash = resultHash * 31 + pRowMap[pRow];
    }
    ac.buildFail();

    string mRow;
    vector<vector<int>> patternBoard;
    for (int i = 0; i < hm; ++i) {
        cin >> mRow;
        ac.search(mRow, patternBoard);
    }
    
    cout << rabinKarp(resultHash, patternBoard);
}