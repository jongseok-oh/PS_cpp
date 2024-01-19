class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return *min_element(matrix[0].begin(), matrix[0].end());
        int ret = 1e9;
        for(int i = 1; i<n; ++i)for(int j = 0; j<n; ++j){
            int val = matrix[i][j];
            matrix[i][j] = 1e9;
            for(int k = -1; k<2; ++k){
                if(j + k >= 0 && j + k <n){
                    matrix[i][j] = min(matrix[i][j], val + matrix[i - 1][j + k]);
                }
            }
            if(i == n-1) ret = min(ret, matrix[i][j]);
        }
        
        return ret;
    }
};