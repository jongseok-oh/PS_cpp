class Solution {
    int calc(vector<vector<int>>& img, int i, int j){
        int n = img.size(), m = img[0].size();
        int cnt = 0, sum = 0;
        for(int ii = -1; ii<2; ++ii) for(int jj = -1; jj<2; ++jj){
            int ny = ii + i, nx = jj + j;
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                sum += img[ny][nx], ++cnt;
            }
        }
        return sum/cnt;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ret(n, vector<int>(m));

        for(int i = 0; i<n; ++i) for(int j = 0; j<m; j++)
            ret[i][j] = calc(img, i,j);

        return ret;
    }
};