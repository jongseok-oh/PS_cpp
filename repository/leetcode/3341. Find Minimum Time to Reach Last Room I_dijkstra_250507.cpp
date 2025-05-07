class Solution {
    using tiii = tuple<int, int, int>;
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9 + 3000));
        dist[0][0] = 0;

        priority_queue<tiii, vector<tiii>, greater<>> q;
        q.push({0,0,0});

        while(q.size()){
            auto [time, y, x] = q.top(); q.pop();

            if(y == n -1 && x == m-1) return time;
            if(time > dist[y][x]) continue;
            
            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

                int nTime = max(time, moveTime[ny][nx]) + 1;
                if(dist[ny][nx] > nTime){
                    dist[ny][nx] = nTime;
                    q.push({nTime, ny, nx});
                }
            }
        }

        return -1;
    }
};