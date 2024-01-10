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
    vector<int> con[100001];
    bool visit[100001];
    void makeGraph(TreeNode* t){
        int val = t->val;
        if(t->right){
            int rv = t->right->val;
            con[val].push_back(rv);
            con[rv].push_back(val);
            makeGraph(t->right);
        }

        if(t->left){
            int lv = t->left->val;
            con[val].push_back(lv);
            con[lv].push_back(val);
            makeGraph(t->left);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        makeGraph(root);

        queue<int> q;
        q.push(start);
        visit[start] = true;

        int ret = -1;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                int t = q.front(); q.pop();
                for(int n: con[t]){
                    if(!visit[n]){
                        visit[n] = true;
                        q.push(n);
                    }
                }
            }
            ret++;
        }

        return ret;
    }
};