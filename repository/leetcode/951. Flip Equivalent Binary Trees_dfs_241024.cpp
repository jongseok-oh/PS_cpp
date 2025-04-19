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
    int parent[100];
    void setP(TreeNode* node, int p, int& cnt){
        if(!node) return;
        int val = node->val;
        ++cnt;
        parent[val] = p;
        setP(node->left, val, cnt);
        setP(node->right, val, cnt);
    }
    bool check(TreeNode* node, int p, int& cnt){
        if(!node) return true;
        int val = node->val;
        if(parent[val] != p) return false;
        ++cnt;
        return check(node->left, val, cnt) && check(node->right, val, cnt);
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        memset(parent, -1, sizeof parent);
        int cnt = 0;
        setP(root1, -2, cnt);
        int cnt2 = 0;
        return check(root2, -2, cnt2) && cnt2 == cnt;
    }
};