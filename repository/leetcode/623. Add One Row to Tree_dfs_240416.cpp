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
    void addOneRow(TreeNode* node, int val, int depth, int targetDepth){
        if(!node) return;
        if(depth == targetDepth - 1){
            TreeNode* left = new TreeNode(val);
            TreeNode* right = new TreeNode(val);
            left->left = node->left;
            node->left = left;
            right->right = node->right;
            node->right = right;
        }else{
            addOneRow(node->left, val, depth + 1, targetDepth);
            addOneRow(node->right, val, depth + 1, targetDepth);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* ret = new TreeNode(val);
            ret->left = root;
            return ret;
        }else {
            addOneRow(root, val,1, depth);
            return root;
        }
    }
};