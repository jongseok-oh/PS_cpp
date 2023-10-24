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
    void solve(int depth, vector<int>& ret, TreeNode* node){
        if(!node) return;
        if(ret.size() <= depth) ret.push_back(node->val);
        else ret[depth] = max(ret[depth], node->val);

        solve(depth + 1, ret, node->left);
        solve(depth + 1, ret, node->right);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        solve(0, ret, root);
        return ret;
    }
};