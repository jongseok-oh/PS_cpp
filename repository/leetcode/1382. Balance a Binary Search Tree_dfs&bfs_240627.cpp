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
    TreeNode* solve(int l, int r, vector<TreeNode*>& tree){
        if(l > r) return 0;
        if(l == r) {
            tree[l]->left = 0;
            tree[l]->right = 0;
            return tree[l];
        }
        int mid = (l + r) >>1;
        tree[mid]->left = solve(l, mid-1, tree);
        tree[mid]->right = solve(mid+1, r, tree);
        return tree[mid];
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> tree;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            TreeNode* node = q.front(); q.pop();
            tree.push_back(node);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        sort(tree.begin(), tree.end(), [&](auto& a, auto& b){
            return a->val < b->val;
        });
        return solve(0, tree.size()-1, tree);
    }
};