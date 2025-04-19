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
    int nodeNum = -1;
    vector<int> con[10000];
    int maxLen = -1, maxNode = -1;
    
    void dfs(TreeNode* root, int prev, int tLen){
        int myNum = ++nodeNum;
        if(prev != -1) {
            con[myNum].push_back(prev);
            con[prev].push_back(myNum);
        }
        if(tLen > maxLen){maxLen = tLen; maxNode = myNum;}
        if(root->left) {dfs(root->left, myNum, tLen + 1);}
        if(root->right) dfs(root->right, myNum, tLen + 1);
    }
    int solve(int t, int prev){
        int ret = 0;
        for(int n: con[t]){
            if(n != prev) ret = max(ret, 1 + solve(n, t));
        }
        return ret;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root, -1, 0);
        return solve(maxNode, -1);
    }
};