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

    long long levelSum[10001];
    int max_level = -1;

    void calc(TreeNode* t, int level){
        if(!t) return;
        max_level = max(max_level, level);
        levelSum[level] += t->val;
        calc(t->left, level + 1);
        calc(t->right, level + 1);
    }

public:
    int maxLevelSum(TreeNode* root) {
        calc(root, 0);

        long long tmax = -0x7fffffffffffffff;
        int ans = -1;

        for(int i = 0; i<=max_level; i++)
            if(tmax < levelSum[i]){
                ans = i + 1;
                tmax = levelSum[i];
            }

        return ans;
    }
};