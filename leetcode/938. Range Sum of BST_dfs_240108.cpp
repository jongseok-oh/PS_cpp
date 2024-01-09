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
    int rangeSumBST(TreeNode* t, int low, int high) {
        if(!t) return 0;
        int ret = 0, val = t->val;
        if(val >= low && val <= high) ret += val;
        return ret + rangeSumBST(t->left, low, high) + rangeSumBST(t->right, low, high);
    }
};