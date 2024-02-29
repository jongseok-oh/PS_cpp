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
    int prev[100000];

    bool dfs(TreeNode* node, int depth){
        int& tPrev = prev[depth];
        int val = node->val;
        if(depth&1){
            if(!tPrev) tPrev = 1e9;
            if(tPrev <= val || val&1) return false;
        }else{
            if(tPrev >= val || !(val&1)) return false;
        }
        tPrev = node->val;
        if(node->left && !(dfs(node->left, depth + 1))) return false;
        if(node->right && !(dfs(node->right, depth + 1))) return false;
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0);
    }
};