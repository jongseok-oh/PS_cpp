class Solution {
    int rowCnt[100];
    int colCnt[100];
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j)
                if(mat[i][j]) ++rowCnt[i];
        
        for(int j = 0; j<m; ++j)
            for(int i = 0; i<n; ++i)
                if(mat[i][j]) ++colCnt[j];
        
        int ret = 0;
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j)
                if(mat[i][j] && rowCnt[i] == 1 && colCnt[j] == 1) ret++;
        
        return ret;
    }
};