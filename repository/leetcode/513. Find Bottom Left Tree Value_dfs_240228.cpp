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
    bool isLeaf(TreeNode* node){
        return !(node->left) && !(node->right);
    }
    int ret = -1, maxDepth = -1;
    void leftmost(TreeNode* node, int depth){
        if(isLeaf(node)){
            if(depth > maxDepth){
                maxDepth = depth;
                ret = node->val;
            }
            return;
        }
        if(node->left)leftmost(node->left, depth + 1);
        if(node->right) leftmost(node->right, depth + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        leftmost(root, 0);
        return ret;
    }
};