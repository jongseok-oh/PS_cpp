class Solution {
    int ret = -1e9;

    int solve(TreeNode* node){
        if(node == nullptr) return 0;
        int left = solve(node->left);
        int right = solve(node->right);

        int temp = node->val;
        if(left >0) temp += left;
        if(right >0) temp += right;

        ret = max(ret, temp);

        return node->val + max({0, left, right});
    }
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ret;
    }
};