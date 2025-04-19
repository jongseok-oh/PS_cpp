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
    struct Tree{
        TreeNode* p;
        TreeNode* q;
    };
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p&&!q) || (!p&&q)) return false;
        queue<Tree> qu;

        qu.push({p,q});

        while(qu.size()){
            Tree t = qu.front(); qu.pop();
            TreeNode* p = t.p;
            TreeNode* q = t.q;

            if(!p && !q) continue;
            if(p->val != q->val) return false;

            TreeNode* pl = p->left; TreeNode* ql = q->left;
            if((!pl && ql) || (pl && !ql)) return false;
            qu.push({pl, ql});

            TreeNode* pr = p->right; TreeNode* qr = q->right;
            if((!pr && qr) || (pr && !qr)) return false;
            qu.push({pr, qr});
        }
        return true;
    }
};