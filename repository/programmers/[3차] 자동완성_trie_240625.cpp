#include <string>
#include <vector>

using namespace std;

struct Node{
    int cnt = 0;
    Node* next[26];
};

struct Trie{
    Node * head = new Node();
    
    void insert(string& s){
        Node* temp = head;
        for(char c : s){
            if(temp->next[c-'a'] == 0) temp->next[c-'a'] = new Node();
            temp = temp->next[c-'a'];
            temp->cnt++;
        }
    }
    int get(string& s){
        Node* temp = head;
        int ret = 0;
        for(char c : s){
            ++ret;
            temp = temp->next[c-'a'];
            if(temp->cnt == 1) break;
        }
        return ret;
    }
};

int solution(vector<string> words) {
    Trie trie;
    for(string& str: words) trie.insert(str);
    int ret = 0;
    for(string& str: words) ret += trie.get(str);
    return ret;
}