class Solution {
    
    struct Loc{int y,x;};

    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {-1,-1,0,1,1,1,0,-1};

    int bfs(vector<vector<int>>& grid){
        if(grid[0][0] == 1) return -1;
        
        int n = grid.size();

        queue<Loc> q;
        q.push({0,0});
        grid[0][0] = 1;

        int ret = 0;

        while(q.size()){
            int qsize = q.size();

            while(qsize--){
                Loc t = q.front(); q.pop();

                if(t.y == n-1 && t.x == n-1) return ret + 1;

                for(int dir = 0; dir<8; dir++){
                    int ny = t.y + dy[dir],
                        nx = t.x + dx[dir];

                    if(ny <0 || ny>=n || nx <0 || nx>=n || grid[ny][nx] == 1) continue;

                    grid[ny][nx] = 1;
                    q.push({ny,nx});
                }
            }
            ret++;
        }
        return -1;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};