class Solution {
    int dist[100][100];

    struct Node{
        int y, x, cost;

        bool operator < (const Node& a) const{
            return this->cost > a.cost;
        }
    };

    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {        
        int n = heights.size(), m = heights[0].size();

        for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j) dist[i][j] = 1e9;

        priority_queue<Node> q;
        
        dist[0][0] = 0;

        q.push({0,0,0});

        while(q.size()){
            Node t = q.top(); q.pop();

            int y = t.y, x = t.x, cost = t.cost;


            if(y == n -1 && x == m-1) return cost;
            if(dist[y][x] < cost) continue;

            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny < 0 || ny >=n || nx <0 || nx >= m) continue;

                int nCost = max(cost, abs(heights[y][x] - heights[ny][nx]));
                if(dist[ny][nx] > nCost){
                    dist[ny][nx] = nCost;
                    q.push({ny,nx, nCost});
                }
            }
        }

        return -1;
    }
};