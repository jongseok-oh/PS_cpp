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
class FindElements {
    unordered_set<int> numCache;
public:
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        root->val = 0;

        q.push(root);
        while(q.size()){
            auto node = q.front(); q.pop();
            int val = node->val;
            numCache.insert(val);
            if(node->left) {
                node->left->val = 2*val + 1;
                q.push(node->left);
            }
            if(node->right) {
                node->right->val = 2*val + 2;
                q.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        return numCache.count(target);
    }
};