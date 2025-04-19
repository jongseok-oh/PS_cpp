class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<int> rowCount(n), colCount(m);

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(grid[i][j] == 1){
                    ++rowCount[i];
                    ++colCount[j];
                }
            }
        }

        int ret = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(grid[i][j] && (rowCount[i]>= 2 || colCount[j]>=2)){
                    ++ret;
                }
            }
        }
        return ret;
    }
};