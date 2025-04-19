class Solution {
    int dp[200][200];

    int solve(int r, int c, vector<vector<int>>& grid){
        int n = grid.size();
        if(r == n) return 0;
        int& ret = dp[r][c];

        if(ret != 0x7f7f7f7f) return ret;

        for(int i = 0; i<n; ++i){
            if(i == c) continue;
            ret = min(ret, grid[r][c] + solve(r + 1, i, grid));
        }
        return ret;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];
        memset(dp, 0x7f, sizeof dp);

        int ret = 1e9;
        for(int i = 0; i<n; ++i)
            ret = min(ret, solve(0,i,grid));
        
        return ret;
    }
};