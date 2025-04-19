class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i<m; ++i) {
            for(int j = 1;j<n; ++j){
                if(matrix[j][i]) matrix[j][i] += matrix[j-1][i];
            }
        }

        int ret = -1;
        for(int i = 0; i<n; ++i){
            sort(matrix[i].begin(),matrix[i].end(), [](int& a, int& b){
                return a > b;
            });

            for(int j = 0; j<m; ++j)
                ret = max(ret, (j + 1) * matrix[i][j]);
        }
        
        return ret;
    }
};