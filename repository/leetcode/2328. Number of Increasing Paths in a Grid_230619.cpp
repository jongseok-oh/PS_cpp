class Solution {
    int MOD = 1e9 + 7;
    struct Loc{int y,x;};

    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,1));

        vector<Loc> order(m*n);

        int idx = 0;

        for(int i = 0; i<m; i++) for(int j  = 0; j<n; j++)
            order[idx++] = {i,j};
        
        sort(order.begin(), order.end(), [&grid](const Loc& a, const Loc& b){
            return grid[a.y][a.x] < grid[b.y][b.x];
        });

        int ans = 0;
        for(auto& loc: order){
            
            int& dpLoc = dp[loc.y][loc.x];

            for(int dir = 0; dir<4; dir++){
                int ny = loc.y + dy[dir];
                int nx = loc.x + dx[dir];

                if(ny <0 || ny >= m || nx <0 || nx >= n) continue;
                if(grid[ny][nx] < grid[loc.y][loc.x]){
                    dpLoc += dp[ny][nx];
                    dpLoc %= MOD;
                }
            }
            
            ans += dpLoc;
            ans %= MOD;
        }

        return ans;
    }
};