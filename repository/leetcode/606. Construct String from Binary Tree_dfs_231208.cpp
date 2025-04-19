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
    void constructString(TreeNode* t, string& ret){
        ret += to_string(t->val);
        if(t->left || t->right) ret += "(";
        if(t->left) constructString(t->left, ret);
        if(t->left || t->right) ret += ")";

        if(t->right){
            ret += "(";
            constructString(t->right, ret);
            ret += ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        string ret = "";
        constructString(root, ret);
        return ret;
    }
};