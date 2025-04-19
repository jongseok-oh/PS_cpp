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
    void dfs(TreeNode* t, vector<int>& ret){
        if(!t) return;
        dfs(t->left, ret);
        ret.push_back(t->val);
        dfs(t->right, ret);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root , ret);
        return ret;
    }
};