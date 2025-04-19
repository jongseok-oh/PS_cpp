class Solution {
    int indeg[20001];
    bool remove[20001];
    vector<int> con[20001];
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        for(auto& edge: edges){
            int a = edge[0], b = edge[1];
            ++indeg[a]; ++indeg[b];
            con[a].push_back(b);
            con[b].push_back(a);
        }

        queue<int> leaves;
        for(int i = 0; i<=n; ++i)
            if(indeg[i] == 1) leaves.push(i);
        
        int nodeCnt = n;
        while(nodeCnt > 2){
            int leafCnt = leaves.size();
            nodeCnt -= leafCnt;

            while(leafCnt--){
                int leaf = leaves.front(); leaves.pop();
                remove[leaf] = true;
                for(int nNode: con[leaf]){
                    if(remove[nNode]) continue;
                    if(--indeg[nNode] == 1) leaves.push(nNode);
                }
            }            
        }

        vector<int> result;
        while(leaves.size()){
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};