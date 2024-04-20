class Solution {
    struct Loc {int y,x;};
    
    int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};
    vector<int> bfs(vector<vector<int>>& land, int y, int x){
        int n = land.size(), m = land[0].size();

        queue<Loc> q;
        q.push({y,x});
        land[y][x] = 0;

        int minX = 1e9, maxX = -1;
        int minY = 1e9, maxY = -1;
        while(q.size()){
            auto [ty, tx] = q.front(); q.pop();
            minX = min(minX, tx); maxX = max(maxX, tx);
            minY = min(minY, ty); maxY = max(maxY, ty);

            for(int dir = 0; dir<4; ++dir){
                int ny = ty + dy[dir], nx = tx + dx[dir];
                if(ny <0 || ny>= n || nx < 0 || nx >= m || land[ny][nx] == 0)
                    continue;
                
                land[ny][nx] = 0;
                q.push({ny,nx});
            }
        }

        return {minY, minX, maxY, maxX};
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        
        vector<vector<int>> result;

        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j)
            if(land[i][j] == 1) result.push_back(bfs(land, i, j));
        
        return result;
    }
};