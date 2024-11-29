class Solution {
    using tiii = tuple<int ,int, int>;
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<tiii, vector<tiii>, greater<>> q;
        if(grid[0][1] <= 1) {
            q.emplace(1, 0, 1);
            dist[0][1] = 1;
        }
        if(grid[1][0] <= 1) {
            q.emplace(1, 1, 0);
            dist[1][0] = 1;
        }

        while(q.size()){
            auto [d, y, x] = q.top(); q.pop();
            if(y == n-1 && x == m-1) return d;
            if(dist[y][x] < d) continue;

            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny <0 || ny>=n || nx<0 || nx>=m) continue;
                
                int nDist = d;
                if(grid[ny][nx] <= d + 1) ++nDist;
                else{
                    nDist = grid[ny][nx] + ((grid[ny][nx] - d)%2 == 0);
                }

                if(dist[ny][nx] > nDist){
                    dist[ny][nx] = nDist;
                    q.emplace(nDist, ny, nx);
                }
            }
        }

        return -1;
    }
};