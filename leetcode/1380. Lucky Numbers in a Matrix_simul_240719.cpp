class Solution {
    int n,m;
    bool isLucky(int r, int c, vector<vector<int>>& matrix){
        int t = matrix[r][c];
        for(int i = 0; i<m; ++i){
            if(matrix[r][i] < t) return false;
        }
        for(int i = 0; i<n; ++i){
            if(matrix[i][c] > t) return false;
        }
        return true;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        n = matrix.size(); m = matrix[0].size();
        vector<int> ret;
        for(int i = 0; i<n; ++i) for (int j = 0; j<m; ++j){
            if(isLucky(i,j, matrix)){
                ret.push_back(matrix[i][j]);
            }
        }
        return ret;
    }
};