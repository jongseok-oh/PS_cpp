class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n*m + 1), col(n*m + 1);
        
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                row[mat[i][j]] = i;
                col[mat[i][j]] = j;
            }
        }

        vector<int> rowCount(n), colCount(m);
        for(int i = 0; i<n*m; ++i){
            int num = arr[i];
            if(++rowCount[row[num]] == m || ++colCount[col[num]] == n){
                return i;
            }
        }
        return -1;
    }
};