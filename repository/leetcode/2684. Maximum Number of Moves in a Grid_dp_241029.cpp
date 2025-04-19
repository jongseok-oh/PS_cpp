class Solution {
    int dy[3] = {-1,0,1}, dx[3] = {1,1,1};
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for(int j = m-2; j>=0; --j){
            for(int i = 0; i<n; ++i){
                for(int dir = 0; dir<3; ++dir){
                    int ny = i + dy[dir], nx = j + dx[dir];
                    if(ny <0 || ny>=n || nx <0 || nx>= m) continue;
                    if(grid[ny][nx] > grid[i][j]){
                        dp[i][j] = max(dp[i][j], 1 + dp[ny][nx]);
                    }
                }
            }
        }
        
        int ret = 0;
        for(int i = 0; i<n; ++i) ret = max(ret, dp[i][0]);
        return ret;
    }
};