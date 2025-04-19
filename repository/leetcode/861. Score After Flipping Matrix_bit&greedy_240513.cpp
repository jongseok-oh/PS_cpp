class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // 맨 앞이 전부 1인게 유리
        int ret = (1<<(m-1))*n;
        for(int j = 1; j<m; ++j){
            int val = 1<<(m-1-j), cnt = 0;
            for(int i = 0; i<n; ++i){
                if(grid[i][j] == grid[i][0]) ++cnt;
            }

            ret += val * max(n-cnt, cnt);
        }

        return ret;
    }
};