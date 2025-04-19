#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Loc{int y,x;};
int dy[] = {1,0,-1,0}, dx[] = {0,1,0,-1};

int oilCount[500];

int n,m;
void bfs(int sy, int sx, vector<vector<int>>& land){
    queue<Loc> q;
    q.push({sy, sx});
    land[sy][sx] = 0;
    
    int count = 0, minX = sx, maxX = sx;
    while(q.size()){
        auto [y, x] = q.front(); q.pop();
        count++;
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny <0 || ny>=n || nx <0 || nx >= m || !land[ny][nx]) continue;
            land[ny][nx] = 0;
            
            minX = min(minX, nx); maxX = max(maxX, nx);
            q.push({ny,nx});
        }
    }
    
    for(int i = minX; i<=maxX; ++i)
        oilCount[i] += count;
}

int solution(vector<vector<int>> land) {
    n = land.size(), m = land[0].size();
    
    for(int i = 0; i<n; ++i) for(int j = 0; j<m; ++j)
        if(land[i][j] == 1) bfs(i,j,land);
    
    int ret = -1;
    for(int i = 0; i<m; ++i) ret = max(ret, oilCount[i]);
    return ret;
}