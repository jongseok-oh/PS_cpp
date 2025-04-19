class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();

        int rIdx = n-1, cIdx = 0;

        int ret = 0;
        while(rIdx >= 0 && cIdx != m){
            while(cIdx != m && grid[rIdx][cIdx] >= 0) cIdx++;
            ret += m - cIdx;
            rIdx--;
        }

        return ret;
    }
};