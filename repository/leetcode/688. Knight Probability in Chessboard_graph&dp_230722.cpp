class Solution {
    double dp[25][25][101];
    int n;
    int dy[8] = {-2,-1,1,2,2,1,-1,-2}, dx[8] = {1,2,2,1,-1,-2,-2,-1};
    double solve(int y, int x, int k){
        if(k == 0) return 1;

        auto& ret = dp[y][x][k];

        if(ret) return ret;

        for(int dir = 0; dir<8; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny >= 0 && ny < n && nx >= 0 && nx < n)
                ret += 0.125 * solve(ny,nx, k-1);
        }
        return ret;
    }
public:
    double knightProbability(int _n, int k, int row, int column) {
        n = _n;
        return solve(row,column, k);
    }
};