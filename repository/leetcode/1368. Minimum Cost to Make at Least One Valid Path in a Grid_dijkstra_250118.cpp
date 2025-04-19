class Solution {
    using tiii = tuple<int, int, int>;
    int dy[5] = {10000, 0, 0, 1, -1}, dx[5] = {10000, 1, -1, 0, 0};
    bool visit[100][100][201];
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<tiii, vector<tiii>, greater<>> q;

        q.emplace(0, 0, 0);
        visit[0][0][0] = true;
        while(q.size()){
            auto [modifyCount, y, x] = q.top(); q.pop();
            if(y == n-1 && x == m-1) return modifyCount;

            for(int dir = 1; dir<5; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];

                if(ny <0 || ny >= n || nx < 0 || nx>=m) continue;
                int nModifyCount = modifyCount + (dir != grid[y][x]);

                if(visit[ny][nx][nModifyCount]) continue;
                visit[ny][nx][nModifyCount] = true;

                q.emplace(nModifyCount, ny, nx);
            }
        }
        return -1;
    }
};