class Solution {
    using pii = pair<int, int>;
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
    int bfs(pii location, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        auto [y,x] = location;
        int ret = grid[y][x];
        grid[y][x] = 0;

        queue<pii> q;
        q.emplace(location);
        while(q.size()){
            auto [ty, tx] = q.front(); q.pop();

            for(int dir = 0; dir<4; ++dir){
                int ny = ty + dy[dir], nx = tx + dx[dir];

                if(ny <0 || ny >= n || nx < 0 || nx >= m || grid[ny][nx] == 0){
                    continue;
                }
                ret += grid[ny][nx];
                grid[ny][nx] = 0;
                q.emplace(ny,nx);
            }
        }

        return ret;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ret = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(grid[i][j] > 0){
                    ret = max(ret, bfs({i,j}, grid));
                }
            }
        }

        return ret;
    }
};