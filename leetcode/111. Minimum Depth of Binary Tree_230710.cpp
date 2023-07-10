class Solution {
    int solve(TreeNode* root){
        int ret = 1e9;

        if(root->left) ret = min(ret, solve(root->left) + 1);
        if(root->right) ret = min(ret, solve(root->right) + 1);

        return (ret==1e9?1:ret);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return solve(root);
    }
};