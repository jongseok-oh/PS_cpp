class Solution {
    const int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};

    void dfs(int y, int x, vector<vector<int>>& grid, vector<vector<bool>>& visit){
        int n = grid.size(), m = grid[0].size();
        visit[y][x] = true;
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny <0 || ny>=n || nx<0 || nx>=m || !grid[ny][nx] || visit[ny][nx]) continue;
            dfs(ny, nx, grid, visit);
        }
    }

    int countIslands(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));

        int ret = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(grid[i][j] && !visit[i][j]){
                    dfs(i, j, grid, visit);
                    ++ret;
                }
            }
        }
        cout<<ret;
        return ret;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        if(countIslands(grid) != 1) return 0;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j){
            if(grid[i][j]){
                grid[i][j] = 0;
                if(countIslands(grid) != 1) return 1;
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};