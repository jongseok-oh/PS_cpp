class Solution {
    using tiii = tuple<int, int, int>;

    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<tiii, vector<tiii>, greater<>> q;

        vector<vector<bool>> visit(n, vector<bool>(m));
        for(int i = 0; i<n; ++i){
            q.emplace(heightMap[i][0], i, 0);
            q.emplace(heightMap[i][m-1], i, m-1);

            visit[i][0] = true;
            visit[i][m-1] = true;
        }

        for(int j = 1; j<m-1; ++j){
            q.emplace(heightMap[0][j], 0, j);
            q.emplace(heightMap[n-1][j], n-1, j);

            visit[0][j] = true;
            visit[n-1][j] = true;
        }

        int ret = 0;
        while(q.size()){
            auto [h, y, x] = q.top(); q.pop();
            
            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny <0 || ny>= n || nx <0 || nx>=m || visit[ny][nx]) continue;

                int nH = heightMap[ny][nx];
                if(nH < h) ret += h - nH;

                visit[ny][nx] = true;
                q.emplace(max(nH, h), ny, nx);
            }
        }
        return ret;
    }
};