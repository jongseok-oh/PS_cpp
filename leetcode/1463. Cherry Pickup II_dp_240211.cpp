class Solution {
    int n,m;
    int dp[70][70][70];

    int solve(int y, int x1, int x2, vector<vector<int>>& grid){
        if(y == n) return 0;
        int& ret = dp[y][x1][x2];
        if(ret != -1) return ret;

        int temp = (x1 == x2?grid[y][x1]:grid[y][x1] + grid[y][x2]);
        ret = temp;

        for(int dir1 = -1; dir1<2; ++dir1){
            int nx1 = x1 + dir1;
            if(nx1 < 0 || nx1 >= m) continue;
            for(int dir2 = -1; dir2<2; ++dir2){
                int nx2 = x2 + dir2;
                if(nx2 < 0 || nx2 >= m) continue;
                ret = max(ret, temp + solve(y + 1, nx1, nx2, grid));
            }
        }

        return ret;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);
        return solve(0, 0, m -1, grid);
    }
};