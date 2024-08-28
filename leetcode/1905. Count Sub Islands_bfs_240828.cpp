class Solution {
    using pii = pair<int,int>;
    const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
    vector<pii> searchIsland(int y, int x,vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        queue<pii> q;
        vector<pii> island;

        q.emplace(y,x);
        island.emplace_back(y,x);
        grid[y][x] = 0;
        
        while(q.size()){
            auto [ty, tx] = q.front(); q.pop();
            
            for(int dir = 0; dir<4; ++dir){
                int ny = ty + dy[dir], nx = tx + dx[dir];
                if(ny <0 || ny>=n || nx < 0 || nx >=m || grid[ny][nx] != 1) continue;
                grid[ny][nx] = 0;
                q.emplace(ny,nx);
                island.emplace_back(ny,nx);
            }
        }

        return island;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();

        int islandNumber = 0;
        for(int i = 0;i<n; ++i) for(int j = 0; j<m; ++j){
            if(grid1[i][j] == 1){
                ++islandNumber;
                vector<pii> island = searchIsland(i, j, grid1);
                for(const auto&[y,x] : island) {
                    grid1[y][x] = islandNumber;
                }
            }
        }

        int ret = 0;
        for(int i = 0;i<n; ++i) for(int j = 0; j<m; ++j){
            if(grid2[i][j] == 1){
                vector<pii> island = searchIsland(i, j, grid2);

                bool allSame = true;
                int islandNum = grid1[island[0].first][island[0].second];
                if(islandNum == 0) continue;
                
                for(int k = 1; k<island.size(); ++k) {
                    const auto&[y,x] = island[k];
                    int tIslandNum = grid1[y][x];
                    if(tIslandNum == 0 || islandNum != tIslandNum){
                        allSame = false; break;
                    }
                }

                ret += allSame;
            }
        }

        return ret;
    }
};