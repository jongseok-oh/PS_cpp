/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void dfs(Node* node, vector<int>& ret){
        if(!node) return;
        for(auto& next : node->children){
            dfs(next, ret);
        }
        ret.push_back(node->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
};