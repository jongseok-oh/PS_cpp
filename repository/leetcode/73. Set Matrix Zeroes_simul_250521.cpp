class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int right = 0, down = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(matrix[i][j] == 0){
                    if(j == 0) ++down;
                    matrix[0][j] = 0;

                    if(i == 0) ++right;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i<n; ++i){
            if(matrix[i][0] == 0){
                for(int j = 1; j<m; ++j) matrix[i][j] = 0;
            }
        }

        for(int i = 1; i<m; ++i){
            if(matrix[0][i] == 0){
                for(int j = 1; j<n; ++j) matrix[j][i] = 0;
            }
        }

        if(right > 0) for(int i = 0; i<m; ++i) matrix[0][i] = 0;
        if(down > 0) for(int i = 0; i<n; ++i) matrix[i][0] = 0;
    }
};