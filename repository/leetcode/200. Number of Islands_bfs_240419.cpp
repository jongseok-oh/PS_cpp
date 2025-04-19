class Solution {
    struct Loc{int y, x;};
    int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};

    void bfs(vector<vector<char>>& grid, int y, int x){
        int n = grid.size(), m = grid[0].size();

        queue<Loc> q;
        q.push({y,x});
        grid[y][x] = '0';

        while(q.size()){
            auto [ty, tx] = q.front(); q.pop();

            for(int dir = 0; dir<4; ++dir){
                int ny = ty + dy[dir], nx = tx + dx[dir];

                if(ny < 0 || ny>=n || nx <0 || nx >= m || grid[ny][nx] == '0') continue;
                q.push({ny,nx});
                grid[ny][nx] = '0';
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ret = 0;
        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j)
            if(grid[i][j] == '1'){
                bfs(grid, i, j);
                ++ret;
            }
        
        return ret;
    }
};