class Solution {
    int maxDepth[100001];
    int levels[100001];
    int dfs(TreeNode* node, int level, vector<vector<int>>& levelTree){
        if(!node) return 0;
        int val = node->val;
        if(levelTree.size() == level){
            levelTree.push_back({});
        }
        levels[val] = level;
        levelTree[level].push_back(val);
        return maxDepth[val] = max({level, dfs(node->left, level + 1, levelTree),
                            dfs(node->right, level + 1, levelTree)});
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> levelTree;
        int _max = dfs(root, 0, levelTree);
        for(auto& level : levelTree){
            sort(level.begin(), level.end(), [&](int l1, int l2){
                return maxDepth[l1] > maxDepth[l2];
            });
        }
        int m = queries.size();
        vector<int> ret(m);
        for(int i = 0; i<m; ++i){
            int q = queries[i], level = levels[q];
            if(maxDepth[q] != _max){
                ret[i] = _max;
            }else if(levelTree[level].size() == 1){
                ret[i] = level -1;
            }else {
                ret[i] = maxDepth[levelTree[level][1]];
            }
        }
        return ret;
    }
};