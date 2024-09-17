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
    int nodeNum = 0;;
    unordered_map<TreeNode*, int> nodeNums;

    void setNodeNum(TreeNode* node){
        nodeNums[node] = ++nodeNum;
        if(node->left) setNodeNum(node->left);
        if(node->right) setNodeNum(node->right);
    }

    void solve(TreeNode* node, vector<vector<int>>& dp){
        if(node->left) solve(node->left, dp);
        if(node->right) solve(node->right, dp);

        int num = nodeNums[node];
        for(int i = 0; i<3; ++i) dp[num][i] = node->val;

        if(node->left){
            int leftNum = nodeNums[node->left];
            dp[num][0] += max({0, dp[leftNum][0], dp[leftNum][1]});
            dp[num][2] += max(0, dp[num][0] - node->val);
        }
        if(node->right){
            int rightNum = nodeNums[node->right];
            dp[num][1] += max({0, dp[rightNum][0], dp[rightNum][1]});
            dp[num][2] += max(0, dp[num][1] - node->val);
        }
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        
        setNodeNum(root);
        vector<vector<int>> dp(nodeNum + 5, vector<int>(3, -1e9));
        solve(root, dp);

        int ret = -1e9;
        for(auto& tdp : dp){
            for(int val : tdp){
                ret = max(ret, val);
            }
        }

        return ret;
    }
};