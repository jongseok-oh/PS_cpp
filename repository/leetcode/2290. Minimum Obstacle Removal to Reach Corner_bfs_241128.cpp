class Solution {
    struct Loc{
        int cnt, y, x;
        Loc(int cnt, int y, int x){
            this->cnt = cnt;
            this->y = y;
            this->x = x;
        }
    };
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));
        
        deque<Loc> q;
        q.emplace_back(0,0,0);
        visit[0][0] = true;

        while(q.size()){
            auto [cnt, y, x] = q.front(); q.pop_front();
            if(y == n-1 && x == m-1) return cnt;

            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny <0 || ny>=n || nx <0 || nx>=m || visit[ny][nx]) continue;
                visit[ny][nx] = true;
                if(grid[ny][nx]){
                    q.emplace_back(cnt + 1, ny, nx);
                }else{
                    q.emplace_front(cnt, ny, nx);
                }
            }
        }

        return -1;
    }
};