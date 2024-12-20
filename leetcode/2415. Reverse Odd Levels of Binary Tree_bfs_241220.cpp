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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> levelNode;

        int level = 0;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                auto node = q.front(); q.pop();
                levelNode.push_back(node);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(level&1){
                for(int i = 0, n = levelNode.size(); i<n/2; ++i){
                    auto n1 = levelNode[i], n2 = levelNode[n - i -1];
                    int temp = n1->val;
                    n1->val = n2->val;
                    n2->val = temp;
                }
            }
            ++level;
            levelNode.clear();
        }

        return root;
    }
};