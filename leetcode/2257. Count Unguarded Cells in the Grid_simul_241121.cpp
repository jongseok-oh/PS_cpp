class Solution {
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> board(m, vector<int>(n));
        for(auto& wall : walls){
            int y = wall[0], x = wall[1];
            board[y][x] = 1;
        }
        for(auto& guard : guards){
            int y = guard[0], x = guard[1];
            board[y][x] = 1;
        }

        for(auto& guard : guards){
            int y = guard[0], x = guard[1];
            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                while(ny>=0 && ny <m && nx >= 0 && nx < n && board[ny][nx] != 1){
                    board[ny][nx] = -1;
                    ny += dy[dir]; nx += dx[dir];
                }
            }
        }

        int ret = 0;
        for(auto& row : board){
            ret += count(row.begin(), row.end(), 0);
        }

        return ret;
    }
};