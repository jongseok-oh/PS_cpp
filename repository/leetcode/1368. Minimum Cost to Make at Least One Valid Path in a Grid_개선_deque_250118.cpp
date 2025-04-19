class Solution {
    int dy[5] = {10000, 0, 0, 1, -1}, dx[5] = {10000, 1, -1, 0, 0};
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // 이 문제처럼 cost의 가중치가 전부 1인 경우
        // dijkstra말고 deque를 통해 heap 정렬을 생략 가능
        deque<pair<int,int>> q;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        q.emplace_front(0, 0);
        dist[0][0] = 0;
        while(q.size()){
            auto [y, x] = q.front(); q.pop_front();
            if(y == n-1 && x == m-1) break;
            
            for(int dir = 1; dir<5; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];

                if(ny <0 || ny >= n || nx < 0 || nx>=m) continue;
                
                int modify = (dir != grid[y][x]);
                if(dist[ny][nx] > dist[y][x] + modify){
                    dist[ny][nx] = dist[y][x] + modify;

                    if(modify == 1){
                        q.emplace_back(ny, nx);
                    }else{
                        q.emplace_front(ny,nx);
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};