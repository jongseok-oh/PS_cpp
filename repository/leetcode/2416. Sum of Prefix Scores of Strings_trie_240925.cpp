class Solution {
    struct Trie{
        struct Node{
            unordered_map<char, Node*> child;
            int cnt;
        };
        Node* root;
        Trie(){
            root = new Node();
        }
        void insert(string& word){
            Node* temp = root;
            for(char c : word){
                if(!(temp->child.count(c))){
                    temp->child[c] = new Node();
                }
                temp->child[c]->cnt++;
                temp = temp->child[c];
            }
        }
        int calcScore(string& word){
            int score = 0;

            Node* temp = root;
            for(char c : word){
                score += temp->child[c]->cnt;
                temp = temp->child[c];
            }

            return score;
        }
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for(string& word : words) trie.insert(word);
        
        int n = words.size();
        vector<int> ret(n);

        for(int i = 0; i<n; ++i){
            ret[i] = trie.calcScore(words[i]);
        }

        return ret;
    }
};