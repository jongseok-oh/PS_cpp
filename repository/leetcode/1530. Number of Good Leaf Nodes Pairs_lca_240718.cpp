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
    const static int _MAX = (1<<10) + 1;
    int d[_MAX];
    int p[_MAX][11];
    int order = 0;

    vector<int> leaves;
    void reorder(TreeNode* node, int parent, int depth){
        if(node == 0) return;
        int me = ++order;
        p[me][0] = parent;
        d[me] = depth;
        
        reorder(node->left, me, depth + 1);
        reorder(node->right, me, depth + 1);
        if(me == order) leaves.push_back(me);
    }

    int getMinPath(int f, int t){
        if(d[f] < d[t]) swap(f,t);
        int path = 0;
        for(int i = 10; i>=0; --i){
            int diff = d[f] - d[t];
            if(diff == 0) break;
            if(diff >= (1<<i)) {
                path += 1<<i;
                f = p[f][i];
            }
        }
        if(f == t) return path;

        for(int i = 10; i>=0; --i){
            if(p[f][i] != p[t][i]){
                path += (1<<i)*2;
                f = p[f][i];
                t = p[t][i];
            }
        }
        return path + 2;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        reorder(root, 0, 0);
        
        for(int i = 1; i<11; ++i){
            for(int j = 1; j<=order; ++j){
                int _p = p[j][i-1];
                p[j][i] = p[_p][i-1];
            }
        }
        
        int ret = 0;
        for(int i = 0, n = leaves.size(); i<n; ++i){
            for(int j = i + 1; j<n; ++j){
                int a = leaves[i], b = leaves[j];
                int minPath = getMinPath(a,b);
                if(minPath <= distance) ++ret;
            }
        }
        return ret;
    }
};