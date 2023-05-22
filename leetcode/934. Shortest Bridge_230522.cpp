class Solution {
public:

    struct Loc{int y,x;};

    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};

    // 하나의 섬을 -1로 바꾸고
    // 섬의 위치를 큐에 담는다.
    void getOneIsland(vector<vector<int>>& grid, queue<Loc>& island, int n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    queue<Loc> q;
                    q.push({i,j});
                    island.push({i,j});
                    grid[i][j] = -1;
                    
                    while(q.size()){
                        int ty = q.front().y;
                        int tx = q.front().x;
                        q.pop();

                        for(int dir = 0; dir<4; dir++){
                            int ny = ty + dy[dir];
                            int nx = tx + dx[dir];

                            if(ny <0 || ny>=n || nx <0 || nx >= n || grid[ny][nx] != 1)
                                continue;
                            
                            grid[ny][nx] = -1;
                            q.push({ny,nx});
                            island.push({ny,nx});
                        }
                    }
                    return;
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        queue<Loc> q;
        int n = grid.size();
        getOneIsland(grid, q, n);
        
        // 섬의 정점들을 순회하며
        // 다른 섬으로 가는 최소치를 얻는다.
        int ans = 0;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                int ty = q.front().y;
                int tx = q.front().x;
                q.pop();

                for(int dir = 0; dir<4; dir++){
                    int ny = ty + dy[dir];
                    int nx = tx + dx[dir];

                    if(ny <0 || ny>=n || nx <0 || nx >= n || grid[ny][nx] == -1)
                        continue;
                        
                    if(grid[ny][nx] == 1) return ans;
                    q.push({ny,nx});
                    grid[ny][nx] = -1;
                }
            }
            ans++;
        }
        return 0;
    }
};