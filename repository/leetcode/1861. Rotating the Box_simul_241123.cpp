class Solution {
    
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();

        vector<vector<char>> rotatedBox(m, vector<char>(n));
        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j){
            rotatedBox[j][n - i - 1] = box[i][j];
        }

        for(int i = m -1; i>=0; --i){
            for(int j = 0; j<n; ++j){
                if(rotatedBox[i][j] != '#') continue;

                int ny = i + 1;
                while(ny < m && rotatedBox[ny][j] == '.') ++ny;

                swap(rotatedBox[i][j], rotatedBox[ny-1][j]);
            }
        }

        return rotatedBox;
    }
};