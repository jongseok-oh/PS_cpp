/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* t, vector<int>& leaf){
        auto l = t->left;
        auto r = t->right;
        if(!l&&!r) {leaf.push_back(t->val); return;}
        if(l) dfs(l, leaf);
        if(r) dfs(r, leaf);
    }
    bool dfs2(TreeNode* t, vector<int>& leaf, int& idx){
        auto l = t->left;
        auto r = t->right;
        if(!l&&!r) {return leaf.size() > idx && leaf[idx++] == t->val;}
        if(l) if(!dfs2(l, leaf, idx)) return false;
        if(r) if(!dfs2(r, leaf, idx)) return false;
        return true;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf;
        dfs(root1, leaf);
        int idx = 0;
        return dfs2(root2, leaf, idx) && leaf.size() == idx;
    }
};