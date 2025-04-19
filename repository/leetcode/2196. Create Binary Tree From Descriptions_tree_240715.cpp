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
        int left = -1, right = -1;
    };

    int findRoot(unordered_set<int>& nodes, unordered_set<int>& indeg){
        for(int node : nodes){
            if(!indeg.count(node)) return node;
        }
        return -1;
    }

    TreeNode* makeTree(int node, unordered_map<int, Node>& info){
        auto me = new TreeNode(node);
        if(info.count(node)){
            if(info[node].left != -1){
                me->left = makeTree(info[node].left, info);
            }
            if(info[node].right != -1){
                me->right = makeTree(info[node].right, info);
            }
        }
        return me;
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> nodes;
        unordered_set<int> indeg;
        unordered_map<int, Node> info;

        for(auto& d : descriptions){
            int p = d[0], c = d[1], isLeft = d[2];
            nodes.insert(p); nodes.insert(c);
            indeg.insert(c);
            if(isLeft) info[p].left = c;
            else info[p].right = c;
        }

        return makeTree(findRoot(nodes, indeg), info);
    }
};