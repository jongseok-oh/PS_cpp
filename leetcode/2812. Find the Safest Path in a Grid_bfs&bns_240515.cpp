class Solution {
    struct Loc{int y,x;};

    const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};

    void makeFactor(queue<Loc>& q, vector<vector<int>>& factor, int n){
        int tFactor = 1;
        while(q.size()){
            int qsize = q.size();

            while(qsize--){
                auto [y,x] = q.front(); q.pop();

                for(int dir = 0; dir<4; ++dir){
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(ny <0 || ny >=n || nx < 0 || nx >= n || factor[ny][nx] != -1)
                        continue;
                    factor[ny][nx] = tFactor;
                    q.push({ny,nx});
                }
            }
            ++tFactor;
        }
    }

    bool canGo(vector<vector<int>>& factor, int mid, int n){
        if(factor[0][0] < mid) return false;

        queue<Loc> q;
        vector<vector<bool>> visit(n, vector<bool>(n));

        visit[0][0] = true;
        q.push({0,0});

        while(q.size()){
            auto [y,x] = q.front(); q.pop();

            if(y == n -1 && x == n-1) return true;

            for(int dir = 0; dir<4; ++dir){
                int ny = y + dy[dir], nx = x + dx[dir];
                if(ny <0 || ny >=n || nx < 0 || nx >= n
                || factor[ny][nx] < mid || visit[ny][nx])
                    continue;
                visit[ny][nx] = true;
                q.push({ny,nx});
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return 0;
        int n = grid.size();

        vector<vector<int>> factor(n, vector<int>(n,-1));

        queue<Loc> q;
        for(int i = 0; i<n; ++i) for(int j = 0; j<n; ++j){
            if(grid[i][j]) {
                q.push({i,j});
                factor[i][j] = 0;
            }
        }
        makeFactor(q, factor, n);

        int low = 0, high = 1000;
        while(low + 1 < high){
            int mid = (low + high) >>1;
            if(canGo(factor, mid, n)) low = mid;
            else high = mid;
        }

        return low;
    }
};