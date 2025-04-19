class Solution {
    int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};
    int getWaterCount(vector<vector<int>>& grid, int y, int x){
        int n = grid.size(), m = grid[0].size();

        int cnt = 0;
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];

            if(ny < 0 || ny >=n || nx < 0 || nx >= m) continue;
            if(grid[ny][nx] == 1) cnt++;
        }

        return 4 - cnt;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ret = 0;
        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j){
            if(grid[i][j] == 1)
                ret += getWaterCount(grid, i, j);
        }

        return ret;
    }
};