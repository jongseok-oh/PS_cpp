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
    int minOperations(vector<int>& values){
        int n = values.size();
        unordered_map<int, int> order;
        vector<int> sorted = values;
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i<n; ++i){
            order[sorted[i]] = i;
        }

        int swapCnt = 0;
        for(int i = 0; i<n; ++i){
            while(order[values[i]] != i){
                swap(values[i], values[order[values[i]]]);
                ++swapCnt;
            }
        }
        return swapCnt;
    }
public:
    int minimumOperations(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        int ret = 0;
        vector<int> values;
        while(q.size()){
            
            int qsize = q.size();
            while(qsize--){
                auto node = q.front(); q.pop();
                values.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret += minOperations(values);
            values.clear();
        }

        return ret;
    }
};