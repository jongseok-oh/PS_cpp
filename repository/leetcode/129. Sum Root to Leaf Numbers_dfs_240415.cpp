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
    int solve(TreeNode* node, int temp){
        if(!(node->left) && !(node->right)) return 10 * temp + node->val;
        int ret = 0;
        if(node->left) ret += solve(node->left, temp*10 + node->val);
        if(node->right) ret += solve(node->right, temp*10 + node->val);
        return ret;
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};