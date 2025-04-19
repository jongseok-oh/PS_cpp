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
    using ll = long long;
public:
    ll kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> sums;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            int qsize = q.size();
            ll sum = 0;
            while(qsize--){
                auto node = q.front(); q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sums.push_back(sum);
        }

        if(sums.size() < k) return -1;
        sort(sums.begin(), sums.end(), greater<>());
        return sums[k-1];
    }
};