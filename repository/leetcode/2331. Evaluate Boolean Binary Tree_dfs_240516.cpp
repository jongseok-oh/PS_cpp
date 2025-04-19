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
public:
    bool evaluateTree(TreeNode* root) {
        int val = root->val;
        if(val < 2) return val;

        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        return val==2?leftVal|rightVal:leftVal&rightVal;
    }
};