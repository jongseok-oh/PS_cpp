class Solution {
    int dp[100][100];

    int solve(int y, int x, int m, int n){
        if(y == m-1 && x == n-1) return 1;

        int& ret = dp[y][x];

        if(ret) return ret;

        if(x + 1 < n) ret += solve(y, x + 1, m, n);
        if(y + 1 < m) ret += solve(y + 1, x, m, n);

        return ret;
    }

public:
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};