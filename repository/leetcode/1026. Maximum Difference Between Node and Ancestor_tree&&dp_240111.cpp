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
    int minDp[5001], maxDp[5001];
    vector<int> leaf;
    int parent[5001];

    void makePCon(TreeNode* t){
        int val = t->val;
        if(parent[val] != -1){
            minDp[val] = min(minDp[parent[val]], val);
            maxDp[val] = max(maxDp[parent[val]], val);
        }else {
            minDp[val] = val;
            maxDp[val] = val;
        }
        auto l = t->left, r = t->right;
        if(l) {
            parent[l->val] = val;
            makePCon(l);
        }
        if(r) {
            parent[r->val] = val;
            makePCon(r);
        }

        if(!l&& !r) leaf.push_back(val);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        memset(parent, -1, sizeof parent);
        makePCon(root);

        int ret = -1;
        for(int tt: leaf) ret = max(ret, maxDp[tt] - minDp[tt]);

        return ret;
    }
};