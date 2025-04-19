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
    int distributeCoins(TreeNode* root, TreeNode* p = NULL) {
        if(!root) return 0;
        
        int move = distributeCoins(root->left, root) + distributeCoins(root->right, root);

        int need = root->val-1;
        if(p) p->val += need;
        
        return move + abs(need);
    }
};