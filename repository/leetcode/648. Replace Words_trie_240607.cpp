class Solution {
    vector<string> split(const string& str, char Delimiter) {
        istringstream iss(str);             
        string buffer;                      
    
        vector<string> result;
        while (getline(iss, buffer, Delimiter)) {
            result.push_back(buffer);               
        }
    
        return result;
    }

    class Trie{
        class Node{
        public:
            Node* child[26];
            bool isEnd = false;
            string origin;
        };
        Node* head = new Node();

    public:
        void insert(const string& str){
            Node* temp = head;
            for(char c : str){
                Node* &tChild = temp->child[c - 'a'];
                if(tChild == 0) tChild = new Node();
                temp = tChild;
            }
            temp->isEnd = true;
            temp->origin = str;
        }

        string getShortPrefix(const string& word){
            Node* temp = head;
            for(char c : word){
                temp = temp->child[c-'a'];
                if(temp == 0) return "";
                if(temp->isEnd) return temp->origin;
            }
            return "";
        }
    };
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(string& dic: dictionary) trie.insert(dic);

        vector<string> words = split(sentence, ' ');
        for(int i = 0; i<words.size(); ++i){
            string& word = words[i];
            string prefix = trie.getShortPrefix(word);
            if(prefix != "") word = prefix;
        }

        string ret = "";
        for(int i = 0; i<words.size(); ++i){
            ret += words[i];
            if(i != words.size() -1) ret += " ";
        }
        return ret;
    }
};