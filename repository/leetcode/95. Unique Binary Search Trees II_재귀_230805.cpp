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
    vector<TreeNode*> solve(int left, int right){

        if(left > right) return {nullptr};

        vector<TreeNode*> ret;

        for(int i = left; i<=right; i++){
            vector<TreeNode*> leftTree = solve(left, i -1);
            vector<TreeNode*> rightTree = solve(i + 1, right);

            for(auto lt: leftTree) for(auto rt: rightTree)
                ret.push_back(new TreeNode(i, lt, rt));
        }

        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};