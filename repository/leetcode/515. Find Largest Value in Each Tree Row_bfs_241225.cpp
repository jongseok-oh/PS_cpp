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
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> ret;
        while(q.size()){
            int qsize = q.size();
            int _max = INT_MIN;
            while(qsize--){
                auto node = q.front(); q.pop();
                if(node->val > _max) _max = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ret.push_back(_max);
            _max = INT_MIN;
        }

        return ret;
    }
};