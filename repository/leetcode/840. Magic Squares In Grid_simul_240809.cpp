class Solution {
    const int allVisit = (1<<9) - 1;
    bool isMagic(int sy, int sx, vector<vector<int>>& grid){
        int sum = 0, visit = 0;
        for(int i = 0; i<3; ++i) {
            int num = grid[sy][sx+i];
            sum += num;
            visit |= (1<<num) - 1;
        }

        for(int y = 1; y<3; ++y){
            int tsum = 0;
            for(int x = 0; x<3; ++x){
                int num = grid[sy+y][sx+x];
                tsum += num;
                visit |= (1<<num) -1;
            }
            if(tsum != sum) return false;
        }

        for(int x = 0; x<3; ++x){
            int tsum = 0;
            for(int y = 0; y<3; ++y){
                int num = grid[sy+y][sx+x];
                tsum += num;
                visit |= (1<<num) -1;
            }
            if(tsum != sum) return false;
        }

        int tsum = 0;
        for(int cnt = 0; cnt<3; ++cnt){
            int num = grid[sy+cnt][sx+cnt];
            tsum += num;
            visit |= (1<<num) -1;
        }
        if(tsum != sum) return false;

        tsum = 0;
        for(int cnt = 0; cnt<3; ++cnt){
            int num = grid[sy+cnt][sx+2-cnt];
            tsum += num;
            visit |= (1<<num) -1;
        }
        if(tsum != sum) return false;

        return allVisit == visit;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        if(row <3 || col < 3) return 0;
        
        int ret = 0;
        for(int i = 0; i<=row-3; ++i){
            for(int j = 0; j<=col-3; ++j){
                if(isMagic(i, j, grid)){
                    ++ret;
                }
            }
        }

        return ret;
    }
};