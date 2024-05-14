class Solution {
    const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};

    int n,m;
    int solve(int y, int x, vector<vector<int>>& grid){
        int ret = 0;
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny < 0 || ny>= n || nx <0 || nx >= m || !grid[ny][nx]) continue;
            int temp = grid[ny][nx];
            grid[ny][nx] = 0;
            ret = max(ret, temp + solve(ny,nx, grid));
            grid[ny][nx] = temp;
        }
        return ret;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();
        
        int ret = 0;
        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j){
            if(grid[i][j]) {
                int temp = grid[i][j];
                grid[i][j] = 0;
                ret = max(ret, temp + solve(i,j,grid));
                grid[i][j] = temp;
            }
        }
        return ret;
    }
};