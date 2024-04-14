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
    int solve(TreeNode* node, bool isLeft){
        if(!(node->left) && !(node->right)){
            return isLeft?node->val:0;
        }
        int ret = 0;
        if(node->left) ret += solve(node->left, true);
        if(node->right) ret += solve(node->right, false);
        return ret;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};