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
    string result = "~";
    void solve(TreeNode* node, string temp){
        string t = string(1, (char)(node->val + 'a')) + temp;
        if(node->left == 0 && node->right == 0){
            if(t < result) result = t;
            return;
        }
        if(node->left) solve(node->left, t);
        if(node->right) solve(node->right, t);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        return result;
    }
};