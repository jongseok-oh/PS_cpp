class Solution {
    const int MOD = 1e9 + 7;
    int dp[50][50][51];
    int n, m;
    
    const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
    int solve(int y, int x, int move){
        if(y<0 || y >= n || x<0 || x >= m) return 1;
        if(move <= 0) return 0;
        int& ret = dp[y][x][move];
        if(ret != -1) return ret;
        
        ret = 0;
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            ret = (ret + solve(ny,nx, move -1)) % MOD;
        }
        return ret;
    }
public:
    int findPaths(int _n, int _m, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        n = _n; m = _m;
        return solve(startRow, startColumn, maxMove);
    }
};