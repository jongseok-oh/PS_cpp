class Solution {
    bool visit[30][30][1<<6];

    struct Loc{int y,x;};
    struct Info{Loc loc; int keys;};
    int keyIdx[26];

    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();

        int keyCnt = 0; Loc start;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++){
            char& tt = grid[i][j];
            if(tt == '@'){
                start = {i,j}; tt = '.';
            }else if(tt >= 'a' && tt <= 'z'){
                keyIdx[tt - 'a'] = keyCnt++;
            }
        }

        queue<Info> q;
        q.push({start, 0});
        
        visit[start.y][start.x][0] = true;

        int tar = ((1<<keyCnt) - 1), ans = 0;
        while(q.size()){
            
            int qsize = q.size();

            while(qsize--){
                auto tInfo = q.front(); q.pop();
                
                int keys = tInfo.keys;
                if(keys == tar) return ans;

                int y = tInfo.loc.y;
                int x = tInfo.loc.x;
                
                for(int dir = 0; dir<4; dir++){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    int tKeys = keys;
                    // 범위 벗어남
                    if(ny < 0 || ny >= n || nx <0 || nx >= m) continue;
                    // 벽이거나 방문함
                    if(grid[ny][nx] == '#' || visit[ny][nx][keys]) continue;
                    // 자물쇠인데 열쇠가 없음
                    if(grid[ny][nx] >= 'A' && grid[ny][nx] <= 'Z'
                    && !(tKeys & (1<<keyIdx[grid[ny][nx] - 'A']))) continue;
                    // 열쇠임 획득! ^^
                    if(grid[ny][nx] >= 'a' && grid[ny][nx] <= 'z')
                        tKeys |= (1<<keyIdx[grid[ny][nx] - 'a']);
                    
                    visit[ny][nx][tKeys] = true;
                    q.push({{ny,nx}, tKeys});
                }
            }
            ans++;
        }

        return -1;
    }
};