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
    bool deleteTarget(TreeNode* node, int target){
        bool noLeft = node->left==0 || deleteTarget(node->left, target);
        bool noRight = node->right==0 || deleteTarget(node->right, target);

        if(noLeft) node->left = 0;
        if(noRight) node->right = 0;

        return noLeft && noRight && node->val == target;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return deleteTarget(root, target)?0:root;
    }
};