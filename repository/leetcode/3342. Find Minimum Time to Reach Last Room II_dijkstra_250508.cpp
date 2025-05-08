class Solution {
    using tiii = tuple<int, int, int>;
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        priority_queue<tiii, vector<tiii>, greater<>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9 + 1e6));

        q.push({0,0,0});
        while(q.size()){
            auto [cost, y, x] = q.top(); q.pop();

            if(y == n-1 && x == m-1) return cost;
            if(dist[y][x] < cost) continue;

            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                
                int nCost = max(moveTime[ny][nx], cost) + (x + y)%2 + 1;
                if(dist[ny][nx] > nCost){
                    dist[ny][nx] = nCost;
                    q.push({nCost, ny, nx});
                }
            }
        }

        return -1;
    }
};