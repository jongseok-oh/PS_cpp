#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Loc{int y,x,preDir, tCost;};

const int dy[] = {1,0,-1,0}, dx[] = {0,1,0,-1};

int minCost[25][25][4];

int bfs(vector<vector<int>>& board){
    int n = board.size();
    queue<Loc> q;
    q.push({0,0,-1,0});
    
    while(q.size()){
        auto [y, x, preDir, tCost] = q.front(); q.pop();
        
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny <0 || ny >=n || nx <0 || nx >=n || board[ny][nx] == 1) continue;
            
            int cost;
            if(preDir == -1) cost = 100;
            else{
                if((preDir^dir)&1) cost = 600;
                else cost = 100;
            }
            
            if(tCost + cost < minCost[ny][nx][dir]){
                minCost[ny][nx][dir] = tCost + cost;
                q.push({ny,nx,dir,tCost + cost});
            }
        }
    }
    
    int ret = 1e9;
    
    for(int i = 0; i<4; ++i)
        if(ret > minCost[n-1][n-1][i])
            ret = minCost[n-1][n-1][i];
    
    return ret;
}

int solution(vector<vector<int>> board) {
    memset(minCost, 0x7f, sizeof minCost);
    return bfs(board);
}