class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> oneRow(n), oneCol(m);

        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j)
            if(grid[i][j]) ++oneRow[i], ++oneCol[j];
        
        vector<vector<int>> ret(n, vector<int>(m));

        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j)
            ret[i][j] = oneRow[i]*2 + oneCol[j]*2 -n -m;
        
        return ret;
    }
};