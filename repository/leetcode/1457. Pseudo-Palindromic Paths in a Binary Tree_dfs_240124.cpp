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
 int cnt[10];
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ++cnt[root->val];
        auto l = root->left;
        auto r = root->right;
        int ret = 0;
        if(!l && !r){
            int oddCnt = 0;
            for(int i = 1; i<10; ++i) oddCnt += cnt[i]&1;
            ret = oddCnt<=1;
        }
        if(l) ret += pseudoPalindromicPaths(l);
        if(r) ret += pseudoPalindromicPaths(r);
        --cnt[root->val];
        return ret;
    }
};