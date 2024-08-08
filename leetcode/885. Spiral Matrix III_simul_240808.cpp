class Solution {
    int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ret;
        ret.push_back({rStart, cStart});

        int tdir = 0, trange = 1;
        int row = rStart, col = cStart;
        while(ret.size() < rows * cols){
            for(int i = 0; i<2; ++i){
                for(int j = 0; j< trange; ++j){
                    row += dy[tdir]; col += dx[tdir];
                    if(row>=0 && row<rows && col>=0 && col < cols){
                        ret.push_back({row, col});
                        if(ret.size() == rows * cols) return ret;
                    }
                }
                tdir = (tdir + 1) % 4;
            }
            ++trange;
        }
        return ret;
    }
};