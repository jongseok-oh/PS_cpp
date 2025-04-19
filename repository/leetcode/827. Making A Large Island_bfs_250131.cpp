class Solution {
    using pii = pair<int, int>;
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};

    void markIslandSize(int y, int x, vector<vector<int>>& grid, vector<int>& islands){
        int n = grid.size();
        queue<pii> q;
        vector<pii> locs;

        q.emplace(y, x);
        locs.emplace_back(y, x);
        grid[y][x] = 0;

        while(q.size()){
            auto [ty, tx] = q.front(); q.pop();

            for(int dir = 0; dir<4; ++dir){
                int ny = ty + dy[dir], nx = tx + dx[dir];

                if(ny <0 || ny >= n || nx <0 || nx >= n || grid[ny][nx] != 1) continue;
                q.emplace(ny, nx);
                locs.emplace_back(ny, nx);
                grid[ny][nx] = 0;
            }
        }
        
        islands.push_back(locs.size());
        int islandNumber = islands.size()-1;
        for(auto& [ty, tx] : locs){
            grid[ty][tx] = islandNumber;
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> islands = {-10000,-10000};
        int ret = 1;
        for(int i = 0; i<n; ++i) for(int j = 0; j<n; ++j){
            if(grid[i][j] == 1){
                markIslandSize(i, j, grid, islands);
                ret = max(ret, islands[grid[i][j]]);
            }
        }

        unordered_set<int> visit;
        for(int i = 0; i<n; ++i) for(int j = 0; j<n; ++j){
            if(grid[i][j] == 0){
                visit.clear();

                int tempSize = 1;
                for(int dir = 0; dir<4; ++dir){
                    int ny = i + dy[dir], nx = j + dx[dir];

                    if(ny <0 || ny >= n || nx <0 || nx >= n
                    || grid[ny][nx] <2
                    || visit.count(grid[ny][nx])) continue;
                    tempSize += islands[grid[ny][nx]];
                    visit.insert(grid[ny][nx]);
                }
                ret = max(ret, tempSize);
            }
        }
        
        return ret;
    }
};