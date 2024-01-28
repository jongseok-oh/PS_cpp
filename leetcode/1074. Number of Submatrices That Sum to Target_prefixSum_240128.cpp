class Solution {
    int rowPreSum[101][100];
    int colPreSum[100][100][101];
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        for(int j = 0; j<m; ++j) for(int i = 0; i<n; ++i){
            rowPreSum[i + 1][j] = rowPreSum[i][j] + matrix[i][j];
        }
        
        for(int rowS = 0; rowS<n; ++rowS) for(int rowE = rowS; rowE<n; ++rowE){
            for(int col = 0; col<m; ++col){
                colPreSum[rowS][rowE][col + 1] = colPreSum[rowS][rowE][col]
                + rowPreSum[rowE + 1][col] - rowPreSum[rowS][col];
            }
        }

        int cnt = 0;
        for(int rowS = 0; rowS<n; ++rowS) for(int rowE = rowS; rowE<n; ++rowE){
            for(int colS = 0; colS<m; ++colS) for(int colE = colS; colE<m; ++colE){
                if(colPreSum[rowS][rowE][colE + 1] - colPreSum[rowS][rowE][colS] == target)
                    ++cnt;
            }
        }

        return cnt;
    }
};