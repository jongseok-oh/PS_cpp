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
    vector<pair<int, char>> con[100001];
    void makeCon(TreeNode* node ,int p){
        int val = node->val;
        if(p != -1) con[val].emplace_back(p, 'U');
        if(node->left){
            con[val].emplace_back(node->left->val, 'L');
            makeCon(node->left, val);
        }
        if(node->right){
            con[val].emplace_back(node->right->val, 'R');
            makeCon(node->right, val);
        }
    }
    int parent[100001];
    char prev[100001];
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        makeCon(root, -1);

        queue<int> q; q.emplace(startValue);
        while(q.size()){
            auto t = q.front(); q.pop();
            if(t == destValue) break;
            for(auto& [to, dir] : con[t]){
                if(parent[to]) continue;
                parent[to] = t; prev[to] = dir;
                q.emplace(to);
            }
        }

        string ret = "";
        for(int v = destValue; v != startValue; v = parent[v]){
            ret.push_back(prev[v]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};