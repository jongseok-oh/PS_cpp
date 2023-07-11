class Solution {
    vector<int> con[501];

    void makeCon(TreeNode* t){
        if(t->left){
            int tval = t->val;
            int lval = t->left->val;
            con[tval].push_back(lval);
            con[lval].push_back(tval);
            makeCon(t->left);
        }

        if(t->right){
            int tval = t->val;
            int rval = t->right->val;
            con[tval].push_back(rval);
            con[rval].push_back(tval);
            makeCon(t->right);
        }
    }

    bool visit[501];
    void getAns(vector<int>& ans, int t, int depth, int k){
        visit[t] = true;
        if(depth == k){ans.push_back(t); return;}

        for(int next: con[t])
            if(!visit[next]) getAns(ans, next, depth + 1, k);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        makeCon(root);
        getAns(ans, target->val, 0, k);
        return ans;        
    }
};