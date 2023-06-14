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
    void search(TreeNode* t, vector<int>& vals){
        vals.push_back(t->val);

        if(t->left) search(t->left, vals);
        if(t->right) search(t->right, vals);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vals;
        search(root, vals);
        sort(vals.begin(), vals.end());

        int ans = 1e9;
        for(int i = 0; i<vals.size()-1; i++)
            ans = min(ans, vals[i+1] - vals[i]);

        return ans;
    }
};