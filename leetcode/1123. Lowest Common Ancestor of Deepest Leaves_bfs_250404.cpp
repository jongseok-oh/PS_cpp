class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> mapper(1001);
        vector<int> parent(1001, -1);
        queue<TreeNode*> q;
        q.push(root);

        vector<TreeNode*> leaves;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                auto p = q.front(); q.pop();

                int pVal = p->val;
                mapper[pVal] = p;
                leaves.push_back(p);

                if(p->left) {
                    q.push(p->left);
                    parent[p->left->val] = pVal;
                }
                if(p->right) {
                    q.push(p->right);
                    parent[p->right->val] = pVal;
                }
            }

            if(q.size()) leaves.clear();
            else break;
        }

        if(leaves.size() == 1) return leaves[0];

        while(true){
            bool allSame = true;
            leaves[0] = mapper[parent[leaves[0]->val]];
            for(int i = 1, n = leaves.size(); i<n; ++i){
                leaves[i] = mapper[parent[leaves[i]->val]];
                if(leaves[i] != leaves[i-1]) allSame = false;
            }
            if(allSame) break;
        }

        return leaves[0];
    }
};