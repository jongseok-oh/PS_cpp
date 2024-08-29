class Solution {
    vector<int> con[1000];
    
    void dfs(int stone, vector<bool>& visit){
        visit[stone] = true;
        for(int next : con[stone]){
            if(!visit[next]){
                dfs(next, visit);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = n = stones.size();
        for(int i = 0; i<n; ++i){
            int ix = stones[i][0], iy = stones[i][1];
            for(int j = 0; j<n; ++j){
                int jx = stones[j][0], jy = stones[j][1];
                if(ix == jx || iy == jy){
                    con[i].push_back(j);
                    con[j].push_back(i);
                }
            }
        }
        
        int groupCnt = 0;
        vector<bool> visit(n);
        for(int i = 0; i<n; ++i){
            if(!visit[i]){
                dfs(i, visit);
                ++groupCnt;
            }
        }

        return n - groupCnt;
    }
};