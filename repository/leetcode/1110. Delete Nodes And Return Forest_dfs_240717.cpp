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
    bool dNode[1001];
    void search(TreeNode* node, vector<TreeNode*>& ret, int p){
        int val = node->val;
        if(dNode[p] && !dNode[val]) ret.push_back(node);
        if(node->left){
            search(node->left, ret, val);
            if(dNode[node->left->val]){
                node->left = 0;
            }
        }
        if(node->right){
            search(node->right, ret, val);
            if(dNode[node->right->val]){
                node->right = 0;
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dNode[0] = true;
        for(int d: to_delete) dNode[d] = true;
        vector<TreeNode*> ret;
        search(root, ret, 0);
        return ret;
    }
};