class Solution {

    struct Loc{int y,x;};

    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};

    bool bfs(int n, int m, int mid, vector<vector<int>>& cells){
        vector<vector<bool>> visit(n, vector<bool>(m, 0));

        for(int i = 0; i<mid; i++)
            visit[cells[i][0] - 1][cells[i][1] - 1] = true;
        
        queue<Loc> q;

        for(int i = 0; i<m; i++)
            if(!visit[0][i]){
                q.push({0,i});
                visit[0][i] = true;
            }
        
        while(q.size()){
            auto loc = q.front(); q.pop();

            int y = loc.y;
            if(y == n - 1) return true;
            int x = loc.x;

            for(int dir = 0; dir < 4; ++dir){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny <0 || ny >= n || nx <0 || nx >= m || visit[ny][nx]) continue;
                visit[ny][nx] = true;
                q.push({ny,nx});
            }
        }

        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0, right = row*col + 1;
        
        while(left + 1 < right){
            int mid = (left + right)>>1;
            if(!bfs(row, col, mid, cells)) right = mid;
            else left = mid;
        }

        return left;
    }
};