class Solution {
    using piii = pair<int, pair<int,int>>;
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));
        
        priority_queue<piii, vector<piii>, greater<>> q;

        q.emplace(make_pair(0, make_pair(0,0)));
        visit[0][0] = true;

        while(q.size()){
            auto [cnt, loc] = q.top(); q.pop();
            auto [y, x] = loc;
            if(y == n -1 && x == m-1) return cnt;

            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny <0 || ny>=n || nx <0 || nx>=m || visit[ny][nx]) continue;
                visit[ny][nx] = true;
                int nCnt = cnt + (grid[ny][nx] == 1);
                
                q.emplace(make_pair(nCnt, make_pair(ny,nx)));
            }
        }

        return -1;
    }
};