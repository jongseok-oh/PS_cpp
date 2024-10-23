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
    struct Node{
        TreeNode* parent;
        TreeNode* node;
    };
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<Node> q;
        q.push({0, root});
        while(q.size()){
            int qsize = q.size();
            int levelSum = 0;
            vector<Node> levelNode;
            unordered_map<TreeNode*, int> brotherSum;
            while(qsize--){
                Node node = q.front(); q.pop();
                levelNode.push_back(node);
                auto treeNode = node.node;
                brotherSum[node.parent] += treeNode->val;
                levelSum += treeNode->val;

                if(treeNode->left){
                    q.push({treeNode, treeNode->left});
                }
                if(treeNode->right){
                    q.push({treeNode, treeNode->right});
                }
            }

            for(auto [p, node] : levelNode){
                node->val = levelSum - brotherSum[p];
            }
        }
        return root;
    }
};