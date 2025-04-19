class Solution {
    class Trie{
        struct Node{
            unordered_map<string, Node*> children;
            bool isEnd;
            string origin;
        };
        Node* head = new Node();

        void dfs(Node* node, vector<string>& ret){
            if(node->isEnd){
                ret.push_back(node->origin);
                return;
            }
            for(auto& [s, n]: node->children){
                dfs(n, ret);
            }
        }
    public:
        void insert(string& folder){
            Node* node = head;
            for(int i = 1, n = folder.size(); i<n; ++i){
                string temp = "";
                while(i < n && folder[i] != '/') {
                    temp.push_back(folder[i++]);
                }
                if(!node->children.count(temp)){
                    node->children[temp] = new Node();
                }
                node = node->children[temp];
            }
            node->isEnd = true;
            node->origin = folder;
        }
        vector<string> getSubFolders(){
            vector<string> ret;
            dfs(head, ret);
            return ret;
        }
    };
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for(auto& f : folder) trie.insert(f);
        return trie.getSubFolders();
    }
};